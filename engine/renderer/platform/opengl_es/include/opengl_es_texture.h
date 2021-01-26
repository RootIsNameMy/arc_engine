//
// Created by martines on 12. 01. 21.
//

#ifndef ARC_ENGINE_OPENGL_ES_TEXTURE_H
#define ARC_ENGINE_OPENGL_ES_TEXTURE_H

#include "texture.h"

namespace arc {
    class OpenGLESTexture: public TextureClass {
    public:
        OpenGLESTexture(const std::string &path);
        OpenGLESTexture(const std::string &name, int width, int height, void *data);
        ~OpenGLESTexture() override;

        unsigned int width() const override { return width_; }

        unsigned int height() const override { return height_; }

        unsigned int depth() const override { return 1; }

        unsigned int renderer_id() const override { return renderer_id_; };

        void set_data(void *data, unsigned int size) override;

        void Bind(unsigned int slot) const override;

        bool Equal(const TextureClass &other) const override{ return renderer_id_ == other.renderer_id(); }

    private:
        uint width_, height_;
        uint renderer_id_;
        uint internal_format_, data_format_;
    };
}

#endif //ARC_ENGINE_OPENGL_ES_TEXTURE_H
