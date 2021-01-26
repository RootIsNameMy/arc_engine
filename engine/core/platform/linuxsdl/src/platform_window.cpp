//
// Created by martines on 3. 01. 21.
//

#include "platform_window.h"
#include "renderer_api.h"
#include "event_handler.h"

namespace arc {
    static bool s_sdl_initialized = false;

    PlatformWindow::PlatformWindow(const WindowProps &props) {
        Init(props);
    }
    void PlatformWindow::Init(const WindowProps &props) {
        data_.title = props.title;
        data_.width = props.width;
        data_.height = props.height;

        logci("Creating window {0} ({1}, {2})",props.title,props.width,props.height);

        if (!s_sdl_initialized) {
            int success = SDL_Init(SDL_INIT_VIDEO);
            arc_core_assert(!success, "Could not initialize SDL!");
            s_sdl_initialized = true;
        }

        window_ = SDL_CreateWindow(props.title.c_str(),SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,props.width,props.height,SDL_WINDOW_OPENGL| SDL_WINDOW_SHOWN|SDL_WINDOW_RESIZABLE);

        context_ =GraphicsContext::CreateOpenGLContext(window_);
        context_->Init();

        set_vsync(true);
    }

    void PlatformWindow::Shutdown() {
        SDL_DestroyWindow(window_);
        SDL_Quit();
    }

    PlatformWindow::~PlatformWindow() {
        Shutdown();
    }

    void PlatformWindow::OnUpdate() {
        SDL_Event e;
        while(SDL_PollEvent(&e)){
            switch (e.type) {
                case SDL_KEYDOWN: // TODO KEY REPEAT ?
                    EventHandler::OnKeyDown(e.key.keysym.sym,false);
                    break;
                case SDL_KEYUP:
                    EventHandler::OnKeyUp(e.key.keysym.sym);
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    EventHandler::OnButtonDown(e.button.button);
                    break;
                case SDL_MOUSEBUTTONUP:
                    EventHandler::OnButtonUp(e.button.button);
                    break;
                case SDL_MOUSEMOTION:
                    EventHandler::OnMove(e.motion.x, e.motion.y);
                    break;
                case SDL_MOUSEWHEEL:
                    EventHandler::OnScroll(e.wheel.x, e.wheel.y);
                    break;
                case SDL_WINDOWEVENT:
                    if(e.window.event == SDL_WINDOWEVENT_RESIZED){
                        EventHandler::OnResize(e.window.data1,e.window.data2);
                    } else if(e.window.event == SDL_WINDOWEVENT_CLOSE){
                        EventHandler::OnClose();
                    }
                    break;
            }
        }
        context_->SwapBuffers();
    }

    void PlatformWindow::set_vsync(bool enabled) {
        if (enabled) {
            SDL_GL_SetSwapInterval(-1);
        } else {
            SDL_GL_SetSwapInterval(0);
        }
        data_.vsync = enabled;
    }

    void PlatformWindow::HideCursor() {
        SDL_ShowCursor(SDL_DISABLE);
    }

    void PlatformWindow::ShowCursor() {
        SDL_ShowCursor(SDL_ENABLE);
    }

    float PlatformWindow::GetTime() {
        return (float)SDL_GetTicks()/1000.0f;
    }

    void PlatformWindow::Resize(int width, int height) {
        data_.width = width;
        data_.height = height;
    }
}
