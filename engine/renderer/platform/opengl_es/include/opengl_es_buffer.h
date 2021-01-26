//
// Created by martines on 12. 01. 21.
//

#ifndef ARC_ENGINE_OPENGL_ES_BUFFER_H
#define ARC_ENGINE_OPENGL_ES_BUFFER_H

#include "buffer.h"

namespace arc {
    class OpenGLESVertexBuffer: public VertexBufferClass {
    public:
        OpenGLESVertexBuffer( uint size);
        OpenGLESVertexBuffer(float *vertices, uint size);
        ~OpenGLESVertexBuffer() override;

        void Bind() const override;

        void Unbind() const override;

        void set_layout(const BufferLayout &layout) override { layout_ = layout; };

        const BufferLayout &layout() const override { return layout_; };

        void SetData(const void *data, uint size) override;

    private:
        BufferLayout layout_{};
        uint renderer_id_;
    };


    class OpenGLESIndexBuffer: public IndexBufferClass {
    public:
        OpenGLESIndexBuffer(uint *indices, uint count);
        OpenGLESIndexBuffer(uint size);
        ~OpenGLESIndexBuffer() override;

        void Bind() const override;

        void Unbind() const override;

        uint count() const override { return count_; }

        void SetData(const void *data, uint size) override;

    private:
        uint count_;
        uint renderer_id_;
    };
}

#endif //ARC_ENGINE_OPENGL_ES_BUFFER_H
