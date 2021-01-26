//
// Created by martines on 12. 01. 21.
//

#include <glad/glad.h>
#include "opengl_es_buffer.h"

namespace arc {

    /////////////////////////////////////////////////////////////////////////////
    // Vertex Buffer ////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////

    OpenGLESVertexBuffer::OpenGLESVertexBuffer(uint size) {
        glGenBuffers(1, &renderer_id_);
        glBindBuffer(GL_ARRAY_BUFFER, renderer_id_);
        glBufferData(GL_ARRAY_BUFFER, size, nullptr, GL_DYNAMIC_DRAW);
    }

    OpenGLESVertexBuffer::OpenGLESVertexBuffer(float *vertices, uint size) {
        glGenBuffers(1, &renderer_id_);
        glBindBuffer(GL_ARRAY_BUFFER, renderer_id_);
        glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
    }

    OpenGLESVertexBuffer::~OpenGLESVertexBuffer() noexcept {
        glDeleteBuffers(1, &renderer_id_);
    }

    void OpenGLESVertexBuffer::Bind() const {
        glBindBuffer(GL_ARRAY_BUFFER, renderer_id_);
    }

    void OpenGLESVertexBuffer::Unbind() const {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    void OpenGLESVertexBuffer::SetData(const void *data, uint size) {
        glBindBuffer(GL_ARRAY_BUFFER, renderer_id_);
        glBufferSubData(GL_ARRAY_BUFFER, 0, size, data);
    }

    /////////////////////////////////////////////////////////////////////////////
    // Index Buffer /////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////

    OpenGLESIndexBuffer::OpenGLESIndexBuffer(uint size) {
        glGenBuffers(1, &renderer_id_);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, renderer_id_);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, nullptr, GL_DYNAMIC_DRAW);
    }

    OpenGLESIndexBuffer::OpenGLESIndexBuffer(uint *indices, uint count):count_(count) {
        glGenBuffers(1, &renderer_id_);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, renderer_id_);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, count* sizeof(indices[0]), indices, GL_STATIC_DRAW);
    }

    OpenGLESIndexBuffer::~OpenGLESIndexBuffer() {
        glDeleteBuffers(1, &renderer_id_);
    }

    void OpenGLESIndexBuffer::Bind() const {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, renderer_id_);
    }

    void OpenGLESIndexBuffer::Unbind() const {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    void OpenGLESIndexBuffer::SetData(const void *data, uint size) {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, renderer_id_);
        glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, size, data);
    }
}