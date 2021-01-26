//
// Created by adolin on 23. 12. 20.
//

#ifndef ARC_ENGINE_BUFFER_H
#define ARC_ENGINE_BUFFER_H
#include "core.h"
namespace arc{
    enum class ShaderDataType {
        None = 0, Float, Float2, Float3, Float4, Mat3, Mat4, Int, Int2, Int3, Int4, Bool
    };

    static uint ShaderDataTypeSize(ShaderDataType type) {
        switch (type) {
            case ShaderDataType::Float:
                return 4;
            case ShaderDataType::Float2:
                return 4 * 2;
            case ShaderDataType::Float3:
                return 4 * 3;
            case ShaderDataType::Float4:
                return 4 * 4;
            case ShaderDataType::Mat3:
                return 4 * 3 * 3;
            case ShaderDataType::Mat4:
                return 4 * 4 * 4;
            case ShaderDataType::Int:
                return 4;
            case ShaderDataType::Int2:
                return 4 * 2;
            case ShaderDataType::Int3:
                return 4 * 3;
            case ShaderDataType::Int4:
                return 4 * 4;
            case ShaderDataType::Bool:
                return 1;
        }
        arc_core_assert(false, "Unknown ShaderDataType!");

    }

    struct BufferElement {
        std::string name;
        ShaderDataType type;
        uint size;
        uint offset;
        bool normalized;

        BufferElement( ShaderDataType _type, const std::string _name, bool _normalized = false) : name(_name), type(_type), size(ShaderDataTypeSize(_type)), offset(0), normalized(_normalized) {

        }


        uint GetComponentCount() const {
            switch (type){
                case ShaderDataType::Float:
                    return 1;
                case ShaderDataType::Float2:
                    return 1 * 2;
                case ShaderDataType::Float3:
                    return 1 * 3;
                case ShaderDataType::Float4:
                    return 1 * 4;
                case ShaderDataType::Mat3:
                    return 1 * 3 * 3;
                case ShaderDataType::Mat4:
                    return 1 * 4 * 4;
                case ShaderDataType::Int:
                    return 1;
                case ShaderDataType::Int2:
                    return 1 * 2;
                case ShaderDataType::Int3:
                    return 1 * 3;
                case ShaderDataType::Int4:
                    return 1 * 4;
                case ShaderDataType::Bool:
                    return 1;
            }
            arc_core_assert(false, "Unknown ShaderDataType!");
        }
    };

    class BufferLayout {
    public:

        BufferLayout(const std::initializer_list<BufferElement>& elements): elements_(elements){
            CalculateOffsetAndStride();
        }


        inline const std::vector<BufferElement> &elements() const { return elements_; }

        inline uint stride() const {return stride_;}


        std::vector<BufferElement>::iterator begin() {return elements_.begin();}
        std::vector<BufferElement>::iterator end() {return elements_.end();}

        std::vector<BufferElement>::const_iterator  begin() const {return elements_.begin();}
        std::vector<BufferElement>::const_iterator end() const {return elements_.end();}


    private:
        void CalculateOffsetAndStride(){
            stride_ = 0;
            for(auto& element: elements_){
                element.offset = stride_;
                stride_+=element.size;
            }
        }
    private:
        std::vector<BufferElement> elements_;
        uint stride_ = 0;
    };


    class VertexBufferClass{
    public:
        virtual ~VertexBufferClass() {}

        virtual void Bind() const = 0;

        virtual void Unbind() const = 0;

        virtual void set_layout(const BufferLayout& layout) = 0;
        virtual  const BufferLayout& layout() const =0;

        virtual void SetData(const void* data, uint size) = 0;

        static VertexBufferClass* Create();
        static VertexBufferClass* Create(float *vertices, uint count);
    };
    class VertexBuffer: public Caller{
    private:
        typedef void(VoidMemberFn)(void*);
        typedef void(VoidMemberBLFn)(void*, const BufferLayout&);
        typedef const BufferLayout&(BLMemberFn)(void*);
        typedef void(VoidMemberVoidUintFn)(void*, const void*, uint);

        VertexBufferClass* vertex_buffer_{nullptr};
        VoidMemberFn* bind_fn_, *unbind_fn_;
        VoidMemberBLFn* set_layout_fn_;
        BLMemberFn* layout_fn_;
        VoidMemberVoidUintFn* set_data_fn_;
        inline void BindFn(){
            bind_fn_ = (VoidMemberFn*)GetVTable(vertex_buffer_)[2]; // destructor takes 2 vtable slots
            unbind_fn_ = (VoidMemberFn*)GetVTable(vertex_buffer_)[3];
            set_layout_fn_ = (VoidMemberBLFn *)GetVTable(vertex_buffer_)[4];
            layout_fn_ = (BLMemberFn *)GetVTable(vertex_buffer_)[5];
            set_data_fn_ = (VoidMemberVoidUintFn *)GetVTable(vertex_buffer_)[6];
        }

    public:
        void Create( uint size);
        void Create(float *vertices, uint count);
        ~VertexBuffer();


        inline void Dispose(){
            if(vertex_buffer_ != nullptr){
                delete vertex_buffer_;
                vertex_buffer_ = nullptr;
            }
        }


        inline void Bind() const{
            bind_fn_(vertex_buffer_);
        }
        inline void Unbind() const{
            unbind_fn_(vertex_buffer_);
        }

        inline void set_layout(const BufferLayout& layout){
            set_layout_fn_(vertex_buffer_,layout);
        }

        inline const BufferLayout& layout() const{
            return layout_fn_(vertex_buffer_);
        }

        inline void SetData(const void* data, uint size){
            set_data_fn_(vertex_buffer_, data, size);
        }


    };

    class IndexBufferClass{
    public:
        virtual ~IndexBufferClass() {}

        virtual void Bind() const = 0;

        virtual void Unbind() const = 0;

        virtual uint count() const = 0;

        virtual void SetData(const void* data, uint size) = 0;


    };
    class IndexBuffer: public Caller{
    private:
        typedef void(VoidMemberFn)(void*);
        typedef uint(UintMemberFn)(void*);
        typedef void(VoidMemberVoidUintFn)(void*, const void*, uint);

        IndexBufferClass* index_buffer_{nullptr};
        VoidMemberFn * bind_fn_;
        VoidMemberFn *unbind_fn_;
        UintMemberFn *count_fn_;
        VoidMemberVoidUintFn *set_data_fn_;
        inline void BindFn(){


            bind_fn_ = (VoidMemberFn*) GetVTable(index_buffer_)[2];
            unbind_fn_ = (VoidMemberFn*) GetVTable(index_buffer_)[3];
            count_fn_ = (UintMemberFn*) GetVTable(index_buffer_)[4];
            set_data_fn_ = (VoidMemberVoidUintFn *) GetVTable(index_buffer_)[5];

        }
    public:

        void Create(uint size);
        void Create(uint* indices, uint count);
        ~IndexBuffer();
        inline void Dispose(){
            if(index_buffer_ != nullptr){
                delete index_buffer_;
                index_buffer_ = nullptr;
            }
        }



        inline void Bind() const {
            bind_fn_(index_buffer_);
        };

        inline void Unbind() const {
            unbind_fn_(index_buffer_);
        };

        inline uint count() const {
            return count_fn_(index_buffer_);
        };

        inline void SetData(const void* data, uint size){
            set_data_fn_(index_buffer_,data,size);
        };

    };
}


#endif //ARC_ENGINE_BUFFER_H
