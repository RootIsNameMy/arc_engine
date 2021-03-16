//
// Created by adolin on 20. 01. 21.
//

#ifndef ARC_ENGINE_IMGUI_LAYER_H
#define ARC_ENGINE_IMGUI_LAYER_H
#include "listeners.h"
namespace arc {
class ImGuiLayer : public arc::MouseListener, arc::KeyboardListener {
 public:
  void Init();
  void Dispose();

  void Begin();
  void End();

  void BlockEvents(bool block) { m_BlockEvents = block; }

  void SetDarkThemeColors();
  bool OnButtonDown(int button) { return m_BlockEvents && WantCaptureMouse(); }
  bool OnButtonUp(int button) { return m_BlockEvents && WantCaptureMouse(); }
  bool OnScroll(double x_offset, double y_offset) {
    return m_BlockEvents && WantCaptureMouse();
  }
  bool OnMove(double x_pos, double y_pos) {
    return m_BlockEvents && WantCaptureMouse();
  }
  bool OnKeyDown(int key, bool repeat) {
    return m_BlockEvents && WantCaptureKeyboard();
  }

  bool OnKeyUp(int key) { return m_BlockEvents && WantCaptureKeyboard(); }

  bool OnChar(uint key_code) { return m_BlockEvents && WantCaptureKeyboard(); }
  bool WantCaptureMouse();
  bool WantCaptureKeyboard();

 private:
  bool m_BlockEvents = true;
  float m_Time = 0.0f;
};

}  // namespace arc

#endif  // ARC_ENGINE_IMGUI_LAYER_H
