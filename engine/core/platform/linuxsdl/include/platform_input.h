//
// Created by martines on 3. 01. 21.
//

#ifndef ARC_ENGINE_LINUX_WINDOW_SDL_H
#define ARC_ENGINE_LINUX_WINDOW_SDL_H

#include "window.h"

#include "graphics_context.h"
#include <SDL.h>
namespace arc {
    typedef struct SDL_Window SDL_Window;
    class PlatformWindow: public WindowClass {
    public:
        PlatformWindow(const WindowProps& props);
        virtual ~PlatformWindow();
        void OnUpdate() override;
        int width() const  override{return data_.width;}
        int height() const  override{return data_.height;}
        void set_vsync(bool enabled)  override;

        void* native_window() const  override{return window_;};
        void HideCursor()  override;
        void ShowCursor()  override;
        float GetTime() override;

        void Resize(int width, int height) override;

    private:
        void Init(const WindowProps &props);

        void Shutdown();

        GraphicsContext* context_;
        SDL_Window * window_;

        struct WindowData {
            std::string title;
            uint width, height;
            bool vsync;

            //EventCallbackFn event_callback;
        };
        WindowData data_;
    };
}

#endif //ARC_ENGINE_LINUX_WINDOW_SDL_H
