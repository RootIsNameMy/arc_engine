//
// Created by adolin on 22. 12. 20.
//

#include "window.h"
#include "core.h"
#include "platform_window.h"
namespace arc{
    void Window::Create(const WindowProps &props) {
        Dispose();
        window_ = new PlatformWindow(props);
    }

    Window::~Window() {
        Dispose();
    }
}