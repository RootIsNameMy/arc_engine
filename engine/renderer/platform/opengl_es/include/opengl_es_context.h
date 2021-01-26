//
// Created by martines on 12. 01. 21.
//
#include "graphics_context.h"
#include <SDL.h>

#ifndef ARC_ENGINE_OPENGL_ES_CONTEXT_H
#define ARC_ENGINE_OPENGL_ES_CONTEXT_H

namespace arc{
    class OpenGLESContext: public GraphicsContext{
    public:
        OpenGLESContext(SDL_Window * window_handle);

        void Init() override;

        void SwapBuffers() override;

    private:
        SDL_Window* window_handle_;
    };
}

#endif //ARC_ENGINE_OPENGL_ES_CONTEXT_H
