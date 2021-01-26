//
// Created by martines on 12. 01. 21.
//

#include <glad/glad.h>
#include "opengl_es_context.h"
#include "core.h"

arc::OpenGLESContext::OpenGLESContext(SDL_Window *window_handle) : window_handle_(window_handle){
    arc_core_assert(window_handle, "Window handle is null!");
}

void arc::OpenGLESContext::Init() {+
    SDL_GL_CreateContext(window_handle_);

    int status = gladLoadGLES2Loader((GLADloadproc)SDL_GL_GetProcAddress);

    arc_core_assert(status, "Failed to initialize Glad!");
    logci("OpenGL Info:");
    logci("  Vendor: {0},", glGetString(GL_VENDOR));
    logci("  Renderer: {0},", glGetString(GL_RENDERER));
    logci("  Version: {0},", glGetString(GL_VERSION));

}

void arc::OpenGLESContext::SwapBuffers() {
    SDL_GL_SwapWindow(window_handle_);
}