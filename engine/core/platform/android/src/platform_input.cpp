//
// Created by martines on 15. 01. 21.
//


#include <unordered_set>
#include "engine.h"
#include "input.h"
#include "SDL.h"
#include "SDL_sensor.h"


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
    // 0 -> Accelerometer (m/s2)
    // 1 -> Gyroscope (rad/s)
    // 2 -> Magnetometer (μT)
    // 3 -> Rotation (rad)
    // 4 -> temperatura
    // 5 -> proximity
    // 6 -> svetloba
    // 7 -> pritisk
    // 8 -> vlaznost

    void AndroidInput::GetAccelerometerData(float *data) {
        static SDL_Sensor* accelerometer = SDL_SensorOpen(0);
        SDL_SensorGetData(accelerometer, data, 3);
    }

    void AndroidInput::GetGyroData(float *data) {
        static SDL_Sensor* gyro = SDL_SensorOpen(1);
        SDL_SensorGetData(gyro, data, 3);
    }

    void AndroidInput::GetMagnetometerData(float *data) {
        static SDL_Sensor* gyro = SDL_SensorOpen(2);
        SDL_SensorGetData(gyro, data, 3);
    }

    void AndroidInput::GetRotationData(float *data) {
        static SDL_Sensor* gyro = SDL_SensorOpen(3);
        SDL_SensorGetData(gyro, data, 3);
    }

    AndroidInput::POWER_STATE AndroidInput::GetBatteryInfo(int *secs, int *pct) {
        SDL_PowerState state = SDL_GetPowerInfo(secs, pct);
        switch (state) {
            case SDL_POWERSTATE_UNKNOWN:
                return AndroidInput::POWER_STATE::UNKNOWN;
            case SDL_POWERSTATE_ON_BATTERY:
                return AndroidInput::POWER_STATE::ON_BATTERY;
            case SDL_POWERSTATE_NO_BATTERY:
                return AndroidInput::POWER_STATE::NO_BATTERY;
            case SDL_POWERSTATE_CHARGING:
                return AndroidInput::POWER_STATE::CHARGING;
            case SDL_POWERSTATE_CHARGED:
                return AndroidInput::POWER_STATE::CHARGED;
        }
    }

    void AndroidInput::GetTemperatureData(float *data) {
        static SDL_Sensor* accelerometer = SDL_SensorOpen(4);
        SDL_SensorGetData(accelerometer, data, 1);
    }

    void AndroidInput::GetProximityData(float *data) {
        static SDL_Sensor* accelerometer = SDL_SensorOpen(5);
        SDL_SensorGetData(accelerometer, data, 1);
    }

    void AndroidInput::GetLightSensorData(float *data) {
        static SDL_Sensor* light_sensor = SDL_SensorOpen(6);
        SDL_SensorGetData(light_sensor, data, 1);
    }

    void AndroidInput::GetPressureData(float *data) {
        static SDL_Sensor* accelerometer = SDL_SensorOpen(7);
        SDL_SensorGetData(accelerometer, data, 1);
    }

    void AndroidInput::GetHumidityData(float *data) {
        static SDL_Sensor* accelerometer = SDL_SensorOpen(8);
        SDL_SensorGetData(accelerometer, data, 1);
    }

}