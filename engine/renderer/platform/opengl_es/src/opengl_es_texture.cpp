//
// Created by martines on 12. 01. 21.
//

#include <glad/glad.h>
#include "opengl_es_texture.h"
#include "../../../../../extern/stb_image/include/image.h"
namespace arc {
    OpenGLESTexture::OpenGLESTexture(const std::string &path) {
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

        glGenTextures(1, &renderer_id_);
        glBindTexture(GL_TEXTURE_2D, renderer_id_);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

        glTexImage2D(GL_TEXTURE_2D, 0, internal_format_, width_, height_, 0 , data_format_, GL_UNSIGNED_BYTE, data);
    }

    OpenGLESTexture::OpenGLESTexture(const std::string &name, int width, int height, void *data) {
        width_ = width;
        height_ = height;
        data_format_ = GL_RGBA;
        internal_format_ = GL_RGBA8;

        glGenTextures(1, &renderer_id_);
        glBindTexture(GL_TEXTURE_2D, renderer_id_);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

        glTexImage2D(GL_TEXTURE_2D, 0, internal_format_, width_, height_,0 , data_format_, GL_UNSIGNED_BYTE, data);
    }

    OpenGLESTexture::~OpenGLESTexture(){
        glDeleteTextures(1, &renderer_id_);
    }

    void OpenGLESTexture::set_data(void *data, unsigned int size) {
        unsigned int bpc = data_format_ == GL_RGBA ? 4 : 3;
        arc_core_assert(size == width_*height_*bpc, "Data must be entire texture!");
        glBindTexture(GL_TEXTURE_2D, renderer_id_);
        glTexImage2D(GL_TEXTURE_2D, 0, internal_format_, width_, height_,0 , data_format_, GL_UNSIGNED_BYTE, data);
    }

    void OpenGLESTexture::Bind(unsigned int slot) const {
        glActiveTexture(GL_TEXTURE0 + slot);
        glBindTexture(GL_TEXTURE_2D, renderer_id_);
    }
}