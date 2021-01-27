//
// Created by adolin on 21. 12. 20.
//

#include "engine.h"
#include "../../renderer/include/renderer_api.h"

#include "event_handler.h"
#ifdef ARC_IMGUI
#define INIT(x) x.Init()
#define DISPOSE(x) x.Dispose()
#define BEGIN(x) x.Begin()
#define END(x) x.End()
#define IMGUI_RENDER(x) x.ImGuiRender()
#else
#define INIT(x)
#define DISPOSE(x)
#define BEGIN(x)
#define END(x)
#define IMGUI_RENDER(x)
#endif
namespace arc{
    Engine* Engine::instance_{nullptr};


    void Engine::GeneralInit() {
        EventHandler::Init();

        window_.Create({config_.title, 1280, 720});

        RenderCommand::Init();
        RenderCommand::SetViewport(0,0,window_.width(),window_.height());

        EventHandler::SubscribeWindow(this,EventHandler::front);
    }

    void Engine::Run() {
        running_ = true;

        INIT(imgui_layer_);
        app_caller_.Init();
        while (running_){

            float time = window_.GetTime();
            delta_time_ = time - last_frame_time_;
            last_frame_time_ = time;

            app_caller_.Update();

            BEGIN(imgui_layer_);
            {
                IMGUI_RENDER(app_caller_);
            }
            END(imgui_layer_);


            window_.OnUpdate();

        }

        app_caller_.Dispose();
        DISPOSE(imgui_layer_);

    }

    bool Engine::OnWindowResize(int width, int height) {
        window_.Resize(width,height);
        RenderCommand::SetViewport(0,0,width,height);
        return false;
    }

    bool Engine::OnWindowClose() {
        running_ = false;
        return true;
    }

    void Engine::SetAppConfig(const Engine::AppConfig &appConfig) {
        config_ = appConfig;
        if(config_.title.empty()){
            config_.title = "Untitled project";
        }
    }


}