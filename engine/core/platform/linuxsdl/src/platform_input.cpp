//
// Created by adolin on 26. 12. 20.
//


#include <unordered_set>
#include "engine.h"
#include "input.h"

namespace arc{

    static std::unordered_set<int> s_pressed_keys;

    bool Input::IsKeyPressed(int key_code, bool repeat) {
        return false;

    }

    bool Input::IsMouseButtonPressed(int button) {
        return false;
    }

    float Input::GetMouseX() {
        return 0;
    }

    float Input::GetMouseY() {
        return 0;
    }

    std::pair<float, float> Input::GetMousePosition() {
        return {0,0};
    }

    void AndroidInput::GetGyroData(float *data) {

    }

    void AndroidInput::GetAccelerometerData(float *data) {

    }


}
