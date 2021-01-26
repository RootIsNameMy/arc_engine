//
// Created by adolin on 23. 12. 20.
//

#include "buffer.h"
#include "renderer_api.h"

#ifdef ARC_PLATFORM_OPENGL
#include "opengl_buffer.h"
#elif ARC_PLATFORM_OPENGL_ES
#include "opengl_es_buffer.h"
#endif
namespace arc{




    void VertexBuffer::Create(uint size) {
        Dispose();

#ifdef ARC_PLATFORM_OPENGL
        vertex_buffer_ = new OpenGLVertexBuffer(size);
#elif ARC_PLATFORM_OPENGL_ES
        vertex_buffer_ = new OpenGLESVertexBuffer(size);
#else
        arc_core_assert(false, "Not Supported");
#endif

        BindFn();
    }
    void VertexBuffer::Create(float *vertices, uint count) {
        Dispose();
#ifdef ARC_PLATFORM_OPENGL
        vertex_buffer_ = new OpenGLVertexBuffer(vertices, count);
#elif ARC_PLATFORM_OPENGL_ES
        vertex_buffer_ = new OpenGLESVertexBuffer(vertices, count);
#else
        arc_core_assert(false, "Not Supported");
#endif

        BindFn();
    }



    VertexBuffer::~VertexBuffer() {
        Dispose();
    }


    void IndexBuffer::Create(uint size) {
        Dispose();
#ifdef ARC_PLATFORM_OPENGL
        index_buffer_ = new OpenGLIndexBuffer(size);
#elif ARC_PLATFORM_OPENGL_ES
        index_buffer_ = new OpenGLESIndexBuffer(size);
#else
        arc_core_assert(false, "Not Supported");
#endif

        BindFn();
    }

    void IndexBuffer::Create(uint *indices, uint count) {
        Dispose();
#ifdef ARC_PLATFORM_OPENGL
        index_buffer_ = new OpenGLIndexBuffer(indices, count);
#elif ARC_PLATFORM_OPENGL_ES
        index_buffer_ = new OpenGLESIndexBuffer(indices, count);
#else
        arc_core_assert(false, "Not Supported");
#endif

        BindFn();
    }

    IndexBuffer::~IndexBuffer() {
        Dispose();
    }
}