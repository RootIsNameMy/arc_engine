//
// Created by adolin on 22. 12. 20.
//

#ifndef ARC_ENGINE_PLATFORM_WINDOW_H
#define ARC_ENGINE_PLATFORM_WINDOW_H

#include "graphics_context.h"
#include <glfw3.h>
#include <window.h>
#include "core.h"

namespace arc{
    class PlatformWindow final: public WindowClass{
    public:
        PlatformWindow(const WindowProps& props);
         virtual ~PlatformWindow();
         void OnUpdate()  override;
         int width() const override{return data_.width;}
         int height() const override{return data_.height;}
         void set_vsync(bool enabled) override;

        void* native_window() const override{return window_;};
         void HideCursor()  override;
         void ShowCursor()  override;
         float GetTime() override;

        void Resize(int width, int height) override;

    private:
        void Init(const WindowProps &props);

        void Shutdown();

        GraphicsContext* context_;
        GLFWwindow* window_;

        struct WindowData {
            std::string title;
            uint width, height;
            bool vsync;
        };
        WindowData data_;

    };
}


#endif //ARC_ENGINE_PLATFORM_WINDOW_H
