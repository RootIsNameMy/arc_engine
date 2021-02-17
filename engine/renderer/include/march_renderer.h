//
// Created by adolin on 23. 12. 20.
//

#ifndef ARC_ENGINE_MARCH_RENDERER_H
#define ARC_ENGINE_MARCH_RENDERER_H

#include <glm.hpp>

#include "font.h"
#include "perspective_camera.h"
#include "shader.h"
#include "texture.h"
#include "vertex_array.h"

namespace arc {

  enum MarchType{
    Sphere = 0,
    Cube = 1
};

struct VertexMarch {
  glm::vec3 pos;
  glm::vec2 tex_coord;
};

class MarchRenderer {
 public:
  void Init();
  void Destroy();
  void Begin();

  void End();

  void DrawBox(const glm::vec3& pos, const glm::vec3& rotation, float radius, const glm::vec4& color);


 private:

  Shader shader_;

  VertexArray vertex_array_;

  IndexBuffer index_buffer_;
  VertexBuffer vertex_buffer_;
};

}  // namespace arc

#endif  // ARC_ENGINE_MARCH_RENDERER_H
