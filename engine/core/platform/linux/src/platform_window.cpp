//
// Created by adolin on 22. 12. 20.
//

#include "platform_window.h"
#include "renderer_api.h"
#include <glfw3.h>
#include "event_handler.h"

namespace arc{
    static bool s_glfw_initialized = false;
    static void GLFWErrorCallback(int error, const char*message){
        logce("GLFW Error ({0}): {1}", error, message);
    }

    PlatformWindow::PlatformWindow(const WindowProps &props) {
        Init(props);
    }
    void PlatformWindow::Init(const WindowProps &props) {
        data_.title = props.title;
        data_.width = props.width;
        data_.height = props.height;

        logci("Creating window {0} ({1}, {2})",props.title,props.width,props.height);

        if (!s_glfw_initialized) {
            // TODO: glfwterminate on system shutdown
            int success = glfwInit();
            arc_core_assert(success, "Could not initialize GLFW!");
            glfwSetErrorCallback(GLFWErrorCallback);

            s_glfw_initialized = true;
        }
        window_ = glfwCreateWindow(props.width,props.height,props.title.c_str(), nullptr, nullptr);

        context_ =GraphicsContext::CreateOpenGLContext(window_);
        context_->Init();

        set_vsync(true);

        glfwSetWindowSizeCallback(window_, [](GLFWwindow *window, int width, int height) {
            EventHandler::OnResize(width,height);
        });

        glfwSetWindowCloseCallback(window_, [](GLFWwindow *window) {
            EventHandler::OnClose();
        });
        glfwSetCharCallback(window_, [](GLFWwindow *window, uint key_code) {
            EventHandler::OnChar(key_code);
        });

        glfwSetKeyCallback(window_, [](GLFWwindow *window, int key, int scan_code, int action, int mods) {
            switch (action) {
                case GLFW_PRESS:
                    EventHandler::OnKeyDown(key, false);
                    break;
                case GLFW_RELEASE:
                    EventHandler::OnKeyUp(key);
                    break;
                case GLFW_REPEAT:
                    EventHandler::OnKeyDown(key,true);
                    break;
            }
        });

        glfwSetMouseButtonCallback(window_, [](GLFWwindow* window, int button, int action, int mods){
            switch (action){
                case GLFW_PRESS:{
                    EventHandler::OnButtonDown(button);
                    break;
                }
                case GLFW_RELEASE:{
                    EventHandler::OnButtonUp(button);
                    break;
                }
            }
        });

        glfwSetScrollCallback(window_, [](GLFWwindow* window, double x_offset, double y_offset){
            EventHandler::OnScroll(x_offset,y_offset);
        });

        glfwSetCursorPosCallback(window_, [](GLFWwindow* window, double x_pos, double y_pos){
            EventHandler::OnMove(x_pos,y_pos);
        });
    }

    void PlatformWindow::Shutdown() {
        glfwDestroyWindow(window_);
    }



    PlatformWindow::~PlatformWindow() {
        Shutdown();
    }

    void PlatformWindow::OnUpdate() {
        glfwPollEvents();
        context_->SwapBuffers();
    }

    void PlatformWindow::set_vsync(bool enabled) {
        if (enabled) {
            glfwSwapInterval(1);
        } else {
            glfwSwapInterval(0);
        }
        data_.vsync = enabled;
    }

    void PlatformWindow::HideCursor() {
        glfwSetInputMode(window_, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    }

    void PlatformWindow::ShowCursor() {
        glfwSetInputMode(window_, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    }

    float PlatformWindow::GetTime() {
        return (float)glfwGetTime();
    }

    void PlatformWindow::Resize(int width, int height) {
        data_.width = width;
        data_.height = height;
    }

}