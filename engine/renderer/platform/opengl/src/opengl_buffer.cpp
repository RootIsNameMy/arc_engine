//
// Created by adolin on 23. 12. 20.
//

#include <glad/glad.h>
#include "../include/opengl_buffer.h"

namespace arc{

    /////////////////////////////////////////////////////////////////////////////
    // Vertex Buffer ////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////


    OpenGLVertexBuffer::OpenGLVertexBuffer(uint size) {
        glCreateBuffers(1, &renderer_id_);
        glBindBuffer(GL_ARRAY_BUFFER, renderer_id_);
        glBufferData(GL_ARRAY_BUFFER, size, nullptr, GL_DYNAMIC_DRAW);
    }

    OpenGLVertexBuffer::OpenGLVertexBuffer(float *vertices, uint size) {
        glCreateBuffers(1, &renderer_id_);
        glBindBuffer(GL_ARRAY_BUFFER, renderer_id_);
        glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);

    }

    OpenGLVertexBuffer::~OpenGLVertexBuffer() {
        glDeleteBuffers(1, &renderer_id_);
    }

    void OpenGLVertexBuffer::Bind() const {
        glBindBuffer(GL_ARRAY_BUFFER, renderer_id_);
    }

    void OpenGLVertexBuffer::Unbind() const {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    void OpenGLVertexBuffer::SetData(const void *data, uint size) {
        glBindBuffer(GL_ARRAY_BUFFER, renderer_id_);
        glBufferSubData(GL_ARRAY_BUFFER, 0, size, data);
    }


    /////////////////////////////////////////////////////////////////////////////
    // Index Buffer /////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////


    OpenGLIndexBuffer::OpenGLIndexBuffer(uint size) {
        glCreateBuffers(1, &renderer_id_);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, renderer_id_);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, nullptr, GL_DYNAMIC_DRAW);
    }

    OpenGLIndexBuffer::OpenGLIndexBuffer(uint *indices, uint count):count_(count) {
        glCreateBuffers(1, &renderer_id_);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, renderer_id_);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, count* sizeof(indices[0]), indices, GL_STATIC_DRAW);
    }


    OpenGLIndexBuffer::~OpenGLIndexBuffer() {
        glDeleteBuffers(1, &renderer_id_);
    }

    void OpenGLIndexBuffer::Bind() const {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, renderer_id_);
    }

    void OpenGLIndexBuffer::Unbind() const {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    void OpenGLIndexBuffer::SetData(const void *data, uint size) {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, renderer_id_);
        glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, size, data);
    }
}
