
//
// Created by adolin on 23. 12. 20.
//

#ifndef ARC_ENGINE_LINE_RENDERER_H
#define ARC_ENGINE_LINE_RENDERER_H

#include <glm.hpp>

#include "font.h"
#include "orthographic_camera.h"
#include "shader.h"
#include "texture.h"
#include "vertex_array.h"

namespace arc {
struct LineVertex {
  glm::vec3 pos;
  glm::vec4 color;
};
class LineRenderer {
 public:
  void Init();
  void Destroy();
  void Begin(const arc::OrthographicCamera& camera);

  void End();

  void DrawLine(const glm::vec3& a, const glm::vec3& b, const glm::vec4& color);

 private:
  void Flush();

  Shader shader_;

  Shader shader_text_;

  VertexArray vertex_array_;

  IndexBuffer index_buffer_;
  VertexBuffer vertex_buffer_;

  uint num_lines_;
  LineVertex* vertices_;
  uint* indices_;
};

}  // namespace arc

#endif  // ARC_ENGINE_LINE_RENDERER_H
