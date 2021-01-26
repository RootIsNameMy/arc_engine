//
// Created by adolin on 26. 12. 20.
//

#include <glad/glad.h>
#include "../include/opengl_texture.h"
#include "../../../../../external/stb_image/include/image.h"
namespace arc{

    OpenGLTexture::OpenGLTexture(const std::string &path) {
        int width, height, channels;

        Image image;
        unsigned char* data;

        image.Load(path, &width, &height, &channels);
        data = image.get_data();

        arc_core_assert(data, "Failed to load Image: {0}", path);


        width_ = width;
        height_ = height;
        GLuint data_format = GL_RGB;
        GLuint internal_format = GL_RGB8;
        if(channels == 4){
            data_format = GL_RGBA;
            internal_format = GL_RGBA8;
        }
        arc_core_assert(channels == 3 || channels == 4, "Format not supported!");

        internal_format_ = internal_format;
        data_format_ = data_format;

        glCreateTextures(GL_TEXTURE_2D, 1, &renderer_id_);
        glTextureStorage2D(renderer_id_, 1, internal_format_, width_, height_);

        glTextureParameteri(renderer_id_, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTextureParameteri(renderer_id_, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        glTextureParameteri(renderer_id_, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTextureParameteri(renderer_id_, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

        glTextureSubImage2D(renderer_id_, 0, 0, 0, width_, height_, data_format_, GL_UNSIGNED_BYTE, data);

    }

    OpenGLTexture::OpenGLTexture(const std::string &name, int width, int height, void *data) {
        width_ = width;
        height_ = height;
        data_format_ = GL_RGBA;
        internal_format_ = GL_RGBA8;



        glCreateTextures(GL_TEXTURE_2D, 1, &renderer_id_);
        glTextureStorage2D(renderer_id_, 1, internal_format_, width_, height_);

        glTextureParameteri(renderer_id_, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTextureParameteri(renderer_id_, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        glTextureParameteri(renderer_id_, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTextureParameteri(renderer_id_, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

        glTextureSubImage2D(renderer_id_, 0, 0, 0, width, height, data_format_, GL_UNSIGNED_BYTE, data);
    }

    OpenGLTexture::~OpenGLTexture() {
        glDeleteTextures(1, &renderer_id_);
    }




    void OpenGLTexture::set_data(void *data, unsigned int size) {
        unsigned int bpc = data_format_ == GL_RGBA ? 4 : 3;
        arc_core_assert(size == width_*height_*bpc, "Data must be entire texture!");
        glBindTexture(GL_TEXTURE_2D, renderer_id_);
        glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, width_, height_,data_format_,GL_UNSIGNED_BYTE, data);
    }

    void OpenGLTexture::Bind(unsigned int slot) const {
        glBindTextureUnit(slot, renderer_id_);
    }




}
