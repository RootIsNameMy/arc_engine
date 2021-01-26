//
// Created by martines on 6. 01. 21.
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
            int success = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_SENSOR);

            arc_core_assert(!success, "Could not initialize SDL!");
            s_sdl_initialized = true;
        } else {
            SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        }
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION,3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION,0);

        window_ = SDL_CreateWindow("test123",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED, data_.width, data_.height,SDL_WINDOW_OPENGL);

        int w,h;
        SDL_GetWindowSize(window_, &w, &h);
        data_.width = w;
        data_.height = h;

        if(window_ == NULL) {
            SDL_Log("Unable to create window: %s", SDL_GetError());
        }
        context_ = GraphicsContext::CreateOpenGLContext(window_);

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
                case SDL_KEYDOWN:
                    SDL_Log("key down");
                    break;
                case SDL_MULTIGESTURE:
                    EventHandler::OnMultiGesture(e.mgesture.x, e.mgesture.y,e.mgesture.dDist, e.mgesture.dTheta);
                    break;
                case SDL_FINGERDOWN:
                    EventHandler::OnTouchDown(e.tfinger.fingerId, e.tfinger.x, e.tfinger.y);
                    break;
                case SDL_FINGERMOTION:
                    EventHandler::OnTouchMove(e.tfinger.fingerId, e.tfinger.dx, e.tfinger.dy);
                    break;
                case SDL_FINGERUP:
                    EventHandler::OnTouchUp(e.tfinger.fingerId, e.tfinger.x, e.tfinger.y);
                    break;
                case SDL_WINDOWEVENT:
                    if(e.window.event == SDL_WINDOWEVENT_RESIZED){
                        EventHandler::OnResize(e.window.data1, e.window.data2);
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
