//
// Created by martines on 12. 01. 21.
//

#include <glad/glad.h>
#include "opengl_es_renderer_api.h"


namespace arc {
    void OpenGLESRendererAPI::Init() {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        logi("Opengl ES renderer api init!");
    }

    void OpenGLESRendererAPI::SetViewport(uint x, uint y, uint width, uint height) {
        glViewport(x, y, width, height);
    }

    void OpenGLESRendererAPI::SetClearColor(const glm::vec4 &color) {
        glClearColor(color.r, color.g, color.b, color.a);
    }

    void OpenGLESRendererAPI::Clear() {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void OpenGLESRendererAPI::DrawIndexed(const VertexArray& vertex_array, uint count) {
        glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, nullptr);
    }
}
