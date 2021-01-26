//
// Created by martines on 12. 01. 21.
//

#include <glad/glad.h>
#include <fstream>
#include "opengl_es_shader.h"
#include <gtc/type_ptr.hpp>
#include "SDL.h"

namespace arc {
    static GLenum ShaderTypeFromString(const std::string &type) {
        if (type == "vertex") return GL_VERTEX_SHADER;
        if (type == "fragment" || type == "pixel") return GL_FRAGMENT_SHADER;
        arc_core_assert(false, "Unknown shader type!");
    }

    OpenGLESShader::OpenGLESShader(const std::string &name, const std::string &vertex_source,
                                   const std::string &fragment_source) : name_(name){
        std::unordered_map<GLenum, std::string> sources;
        sources[GL_VERTEX_SHADER] = vertex_source;
        sources[GL_FRAGMENT_SHADER] = fragment_source;
        Compile(sources);
    }

    OpenGLESShader::OpenGLESShader(std::string file_path) {
        std::string source = ReadFile(file_path);
        auto shader_sources = PreProcess(source);
        Compile(shader_sources);

        //extract name from file path
        auto last_slash = file_path.find_last_of("/\\");
        last_slash = last_slash == std::string::npos ? 0 : last_slash + 1;
        auto count = file_path.size() - last_slash;
        name_ = file_path.substr(last_slash, count);
    }

    std::string OpenGLESShader::ReadFile(const std::string &file_path) {
        std::string result;
        SDL_RWops *io = SDL_RWFromFile(file_path.c_str(),"rb");

        if(io != nullptr){
            SDL_RWseek(io,0, RW_SEEK_END);
            result.resize(SDL_RWtell(io));
            SDL_RWseek(io,0, RW_SEEK_SET);
            SDL_RWread(io, &result[0], result.size(),1);
            SDL_RWclose(io);
        } else {
            SDL_Log("Error: %s", SDL_GetError());
            arc_core_assert(false, "Could not open file: {0}", file_path);
        }

        return result;
    }

    std::unordered_map<uint, std::string> OpenGLESShader::PreProcess(const std::string &source) {
        std::unordered_map<uint, std::string> shader_sources;

        const char *type_token = "#type";
        size_t type_token_length = strlen(type_token);
        size_t pos = source.find(type_token, 0);
        while (pos != std::string::npos) {
            size_t eol = source.find_first_of("\r\n", pos);
            arc_core_assert(eol != std::string::npos, "Syntax error in shader file!");
            size_t begin = pos + type_token_length + 1;
            std::string type = source.substr(begin, eol - begin);
            arc_core_assert(type == "vertex" || type == "fragment" || type == "pixel",
                            "Invalid shader type specified!");

            size_t next_line_pos = source.find_first_of("\r\n", eol);
            pos = source.find(type_token, next_line_pos);
            shader_sources[ShaderTypeFromString(type)] = source.substr(next_line_pos+1,pos - (next_line_pos == std::string::npos ? source.size() - 1: next_line_pos));
        }
        return shader_sources;
    }

    void OpenGLESShader::Compile(const std::unordered_map<uint, std::string> &shader_sources) {
        GLuint program = glCreateProgram();
        arc_core_assert(shader_sources.size() <= 2, "Only support two shaders for now!");
        std::array<uint, 2> gl_shader_ids;
        int gl_shader_id_index = 0;
        for (auto &kv: shader_sources) {
            GLenum type = kv.first;

            GLuint shader = glCreateShader(type);

            const GLchar *source = kv.second.c_str();
            glShaderSource(shader, 1, &source, 0);

            glCompileShader(shader);

            GLint isCompiled = 0;
            glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);

            if (isCompiled == GL_FALSE) {
                GLint maxLength = 0;
                glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);

                // The maxLength includes the NULL character
                std::vector<GLchar> infoLog(maxLength);
                glGetShaderInfoLog(shader, maxLength, &maxLength, &infoLog[0]);

                // We don't need the shader anymore.
                glDeleteShader(shader);

                // Use the infoLog as you see fit.
                logce("{0}", infoLog.data());
                SDL_Log("Error: %s",infoLog.data());
                arc_core_assert(false, "Shader compilation failure!");
                break;
            }

            glAttachShader(program, shader);
            gl_shader_ids[gl_shader_id_index++] = shader;
        }

        renderer_id_ = program;

        // Link our program
        glLinkProgram(renderer_id_);

        // Note the different functions here: glGetProgram* instead of glGetShader*.
        GLint isLinked = 0;
        glGetProgramiv(renderer_id_, GL_LINK_STATUS, (int *) &isLinked);

        if (isLinked == GL_FALSE) {
            GLint maxLength = 0;
            glGetProgramiv(renderer_id_, GL_INFO_LOG_LENGTH, &maxLength);

            // The maxLength includes the NULL character
            std::vector<GLchar> infoLog(maxLength);
            glGetProgramInfoLog(renderer_id_, maxLength, &maxLength, &infoLog[0]);

            // We don't need the program anymore.
            glDeleteProgram(renderer_id_);

            // Don't leak shaders either.
            for (auto shader: gl_shader_ids) {
                glDeleteShader(shader);
            }

            logce("{0}", infoLog.data());
            arc_core_assert(false, "Linking of shaders failed!");
        }

        // Always detach shaders after a successful link.
        for (auto shader: gl_shader_ids) {
            glDetachShader(renderer_id_, shader);
        }
    }

    OpenGLESShader::~OpenGLESShader() {
        glDeleteProgram(renderer_id_);
    }

    void OpenGLESShader::Bind() const {
        glUseProgram(renderer_id_);
    }

    void OpenGLESShader::Unbind() const {
        glUseProgram(0);
    }

    void OpenGLESShader::SetFragOutput(unsigned int color, const std::string &name) {
        glBindFragDataLocation(renderer_id_,color,name.c_str());
    }

    void OpenGLESShader::SetInt(const std::string &name, int value) {
        UploadUniformInt(name, value);
    }

    void OpenGLESShader::SetIntArray(const std::string &name, int *values, unsigned int count) {
        UploadUniformIntArray(name, values, count);
    }

    void OpenGLESShader::SetFloat(const std::string &name, float value) {
        UploadUniformFloat(name, value);
    }
    void OpenGLESShader::SetFloat2(const std::string &name, const glm::vec2 &value) {
        UploadUniformFloat2(name,value);
    }
    void OpenGLESShader::SetFloat3(const std::string &name, const glm::vec3 &value) {
        UploadUniformFloat3(name, value);
    }

    void OpenGLESShader::SetFloat4(const std::string &name, const glm::vec4 &value) {
        UploadUniformFloat4(name, value);
    }

    void OpenGLESShader::SetMat4(const std::string &name, const glm::mat4 &value) {
        UploadUniformMat4(name, value);
    }

    void OpenGLESShader::UploadUniformInt(const std::string &name, int value) const {
        GLint location = glGetUniformLocation(renderer_id_, name.c_str());
        glUniform1i(location, value);
    }

    void OpenGLESShader::UploadUniformIntArray(const std::string &name, int *values, unsigned int count) const {
        GLint location = glGetUniformLocation(renderer_id_, name.c_str());
        glUniform1iv(location, count,values);
    }

    void OpenGLESShader::UploadUniformFloat(const std::string &name, float value) const {
        GLint location = glGetUniformLocation(renderer_id_, name.c_str());
        glUniform1f(location, value);
    }

    void OpenGLESShader::UploadUniformFloat2(const std::string &name, const glm::vec2 &values) const {
        GLint location = glGetUniformLocation(renderer_id_, name.c_str());
        glUniform2f(location, values.x, values.y);
    }

    void OpenGLESShader::UploadUniformFloat3(const std::string &name, const glm::vec3 &values) const {
        GLint location = glGetUniformLocation(renderer_id_, name.c_str());
        glUniform3f(location, values.x, values.y, values.z);
    }

    void OpenGLESShader::UploadUniformFloat4(const std::string &name, const glm::vec4 &values) const {
        GLint location = glGetUniformLocation(renderer_id_, name.c_str());
        glUniform4f(location, values.x, values.y, values.z, values.w);
    }

    void OpenGLESShader::UploadUniformMat3(const std::string &name, const glm::mat3 &matrix) const {
        GLint location = glGetUniformLocation(renderer_id_, name.c_str());
        glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
    }

    void OpenGLESShader::UploadUniformMat4(const std::string &name, const glm::mat4 &matrix) const {
        GLint location = glGetUniformLocation(renderer_id_, name.c_str());
        glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
    }
}