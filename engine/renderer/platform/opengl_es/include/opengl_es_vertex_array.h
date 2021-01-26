//
// Created by martines on 12. 01. 21.
//

#ifndef ARC_ENGINE_OPENGL_ES_VERTEX_ARRAY_H
#define ARC_ENGINE_OPENGL_ES_VERTEX_ARRAY_H

#include "vertex_array.h"

namespace arc {
    class OpenGLESVertexArray: public VertexArrayClass {
    public:
        OpenGLESVertexArray();
        virtual ~OpenGLESVertexArray();

        void Bind() const override ;

        void Unbind() const override ;

        void BindVertexBuffer(const VertexBuffer& vertex_buffer) override;

        void BindIndexBuffer(const IndexBuffer& index_buffer) override;

    private:
        uint renderer_id_;

    };
}
#endif //ARC_ENGINE_OPENGL_ES_VERTEX_ARRAY_H
