//
// Created by adolin on 21. 12. 20.
//

#include "opengl_renderer_api.h"

#include <glad/glad.h>
namespace arc{
    void OpenGLRendererAPI::Init() {
        logi("Opengl renderer api init!");
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    }

    void OpenGLRendererAPI::SetViewport(uint x, uint y, uint width, uint height) {
        glViewport(x,y,width,height);
    }

    void OpenGLRendererAPI::SetClearColor(const glm::vec4 &color) {
        glClearColor(color.r, color.g, color.b, color.a);
    }

    void OpenGLRendererAPI::Clear() {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void OpenGLRendererAPI::DrawIndexed(const VertexArray& vertex_array, uint count) {
        glDrawElements(GL_TRIANGLES, count,GL_UNSIGNED_INT, nullptr);
    }

}

