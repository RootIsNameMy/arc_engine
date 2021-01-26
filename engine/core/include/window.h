//
// Created by adolin on 22. 12. 20.
//

#ifndef ARC_ENGINE_WINDOW_H
#define ARC_ENGINE_WINDOW_H

#include <string>
#include "core.h"

namespace arc{


    struct WindowProps {
        std::string title;
        int width;
        int height;

        WindowProps(const std::string &title = "Arc Engine", uint width = 1280, uint height = 720)
                : title(title), width(width),
                  height(height) {}
    };



    class WindowClass {
    public:
        virtual void OnUpdate()=0;
        virtual int width() const = 0;
        virtual int height() const = 0;
        virtual void set_vsync(bool enabled) = 0;
        virtual void* native_window() const = 0;
        virtual void HideCursor() = 0;
        virtual void ShowCursor() = 0;
        virtual float GetTime() = 0;
        virtual void Resize(int width, int height) = 0;

        virtual ~WindowClass()= default;
    };

    class Window{


        Window(const Window&);
        Window& operator=(const Window&);
        WindowClass* window_{nullptr};

    public:
        Window() = default;

        void Create(const WindowProps& props);
        ~Window();
        inline void Dispose(){
            if(window_ != nullptr){
                delete window_;
                window_ = nullptr;
            }
        }

        inline void OnUpdate(){
            window_->OnUpdate();
        }
        inline int width() const{
            return window_->width();
        }
        inline int height() const{
            return window_->height();
        }
        inline void set_vsync(bool enable) const{
            window_->set_vsync(enable);
        }
        inline void* native_window() const{
            return window_->native_window();
        }
        inline void HideCursor() const{
            window_->HideCursor();
        }
        inline void ShowCursor() const{
            window_->ShowCursor();
        }
        inline float GetTime() const{
            return window_->GetTime();
        }

        inline void Resize(int width, int height){
            window_->Resize(width,height);
        }
    };
}



#endif //ARC_ENGINE_WINDOW_H
