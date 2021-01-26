//
// Created by adolin on 21. 12. 20.
//

#ifndef ARC_ENGINE_ENGINE_H
#define ARC_ENGINE_ENGINE_H

#include <renderer_api.h>
#include "imgui_layer.h"
#include "../include/application.h"
#include "listeners.h"
#include "window.h"
#include "event_handler.h"

namespace arc{


    class Engine : public WindowListener{
    public:

        struct AppConfig{
            std::string asset_folder;
        };
        struct RendererConfig{
            // contains graphics card capabilities (max texture slots, max vertices in a draw call..)
        };
        struct EngineConfig{
            // contains asset folders for the engine (assets, shaders..)
        };

        template<typename T>
        inline void LaunchDesktopApp(const AppConfig& config){//TODO: add LaunchAndroidApp
            LOG_INIT();
            logci("DELA");
            arc_core_assert(instance_ == nullptr,"Application already exists");
            instance_ = this;
            config_ = config;//TODO: check config asset folder (set to executable location if not set) also set to android
            logce("test");
            EventHandler::Init();

            window_.Create({"Arc Engine", 1280, 720});

            RenderCommand::Init();
            RenderCommand::SetViewport(0,0,window_.width(),window_.height());

            EventHandler::SubscribeWindow(this,EventHandler::front);



            app_caller_.Create(new T());
            Run();
        }
        bool OnWindowResize(int width, int height) override;
        bool OnWindowClose() override;

        static inline const Window& window() {return instance_->window_;}

        static double delta_time() {return instance_->delta_time_;}
        static double running_time() {return instance_->last_frame_time_;}

        static const AppConfig& config() {return instance_->config_;}
    private:

        static Engine* instance_;
        ApplicationCaller app_caller_;
        AppConfig config_;

        Window window_;

        bool running_;
        double last_frame_time_, delta_time_;

        ImGuiLayer imgui_layer_;


        void Run();


    };
}



#endif //ARC_ENGINE_ENGINE_H
