//
// Created by adolin on 22. 12. 20.
//

#include <glad/glad.h>
#include "opengl_context_sdl.h"
#include "core.h"

arc::OpenGLSDLContext::OpenGLSDLContext(SDL_Window* window_handle) :window_handle_(window_handle){
    arc_core_assert(window_handle, "Window handle is null!");
}

void arc::OpenGLSDLContext::Init() {
    SDL_GL_CreateContext(window_handle_);

    int status = gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress);
    arc_core_assert(status, "Failed to initialize Glad!");
    logci("OpenGL Info:");
    logci("  Vendor: {0},", glGetString(GL_VENDOR));
    logci("  Renderer: {0},", glGetString(GL_RENDERER));
    logci("  Version: {0},", glGetString(GL_VERSION));

}

void arc::OpenGLSDLContext::SwapBuffers() {
    SDL_GL_SwapWindow(window_handle_);
}
