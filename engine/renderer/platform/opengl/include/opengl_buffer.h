//
// Created by adolin on 23. 12. 20.
//

#ifndef ARC_ENGINE_OPENGL_BUFFER_H
#define ARC_ENGINE_OPENGL_BUFFER_H


#include "buffer.h"

namespace arc{
    class OpenGLVertexBuffer: public VertexBufferClass{
    public:
        OpenGLVertexBuffer( uint size);
        OpenGLVertexBuffer(float *vertices, uint size);
        ~OpenGLVertexBuffer() override;

        void Bind() const override;

        void Unbind() const override;

        void set_layout(const BufferLayout &layout) override {layout_ = layout;};

        const BufferLayout &layout() const override{return layout_;};

        void SetData(const void *data, uint size) override;

    private:
        BufferLayout layout_{};
        uint renderer_id_;
    };


    class OpenGLIndexBuffer: public IndexBufferClass{
    public:
        OpenGLIndexBuffer(uint *indices, uint count);
        OpenGLIndexBuffer(uint size);
        ~OpenGLIndexBuffer() override;

        void Bind() const override;

        void Unbind() const override;

        uint count() const override{return count_;}

        void SetData(const void *data, uint size) override;

    private:
        uint count_;
        uint renderer_id_;
    };
}


#endif //ARC_ENGINE_OPENGL_BUFFER_H
