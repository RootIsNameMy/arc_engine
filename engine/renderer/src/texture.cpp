//
// Created by adolin on 26. 12. 20.
//

#include "texture.h"
#include "renderer_api.h"


#ifdef ARC_PLATFORM_OPENGL
#include "opengl_texture.h"
#elif ARC_PLATFORM_OPENGL_ES
#include "opengl_es_texture.h"
#endif
namespace arc {


    void Texture::Create2D(const std::string &path) {
        Dispose();
#ifdef ARC_PLATFORM_OPENGL
        texture_ = new OpenGLTexture(path);
#elif ARC_PLATFORM_OPENGL_ES
        texture_ = new OpenGLESTexture(path);
#else
        arc_core_assert(false, "Not Supported");
#endif

        BindFn();
    }

    void Texture::Create2D(const std::string &name, int width, int height, void *data) {
        Dispose();
#ifdef ARC_PLATFORM_OPENGL
        texture_ = new OpenGLTexture(name, width, height,data);
#elif ARC_PLATFORM_OPENGL_ES
        texture_ = new OpenGLESTexture(name, width, height,data);
#else
        arc_core_assert(false, "Not Supported");
#endif

        BindFn();
    }

    Texture::~Texture() {
        Dispose();
    }
}
