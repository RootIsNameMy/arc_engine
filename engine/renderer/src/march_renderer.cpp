
//
// Created by adolin on 23. 12. 20.
//

#include "march_renderer.h"

#include <engine.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/rotate_vector.hpp>

#include "renderer_api.h"
namespace arc {

void MarchRenderer::Init() {
  vertex_array_.Create();

  vertex_buffer_.Create(4 * sizeof(VertexMarch));
  vertex_buffer_.set_layout({
      {ShaderDataType::Float3, "a_position"},
      {ShaderDataType::Float2, "a_tex_coord"},
  });

  vertex_array_.AddVertexBuffer(vertex_buffer_);

  uint* indices_ = new uint[6];

  uint vertex_index = 0;
  for (int i = 0; i < 6; i += 6) {
    indices_[i + 0] = vertex_index;
    indices_[i + 1] = vertex_index + 1;
    indices_[i + 2] = vertex_index + 2;

    indices_[i + 3] = vertex_index + 2;
    indices_[i + 4] = vertex_index + 3;
    indices_[i + 5] = vertex_index;
    vertex_index += 4;
  }

  index_buffer_.Create(indices_, 6);
  vertex_array_.set_index_buffer(index_buffer_);

  // shader_.Create("/home/martines/Desktop/git_repos/arc_engine/engine/shaders/2d_shader");
  shader_.Create(
      "/home/tilen/Projects/arc_template/arc_engine/engine/shaders/"
      "march_shader");
  // shader_.Create("2d_shader/opengles.glsl");
}

void MarchRenderer::Destroy() {}

void MarchRenderer::Begin() {
  shader_.Bind();
  vertex_array_.Bind();
  VertexMarch array[4];
  float aspect = Engine::window().width() / (float)Engine::window().height();
  array[0].pos = {-1, -1, 0};
  array[1].pos = {1, -1, 0};
  array[2].pos = {1, 1, 0};
  array[3].pos = {-1, 1, 0};

  array[0].tex_coord = {-aspect, -1};
  array[1].tex_coord = {aspect, -1};
  array[2].tex_coord = {aspect, 1};
  array[3].tex_coord = {-aspect, 1};

  vertex_buffer_.SetData(array, 4 * sizeof(VertexMarch));
  vertex_array_.set_index_buffer(index_buffer_);
  RenderCommand::DrawIndexed(vertex_array_, 6);

  vertex_array_.Unbind();
  shader_.Unbind();
}

void MarchRenderer::End() {}
// TODO: copy in function doesnt work vim (if functio paraeters arent in same
// line)

void MarchRenderer::DrawBox(const glm::vec3& pos, const glm::vec3& rotation,
                            float radius, const glm::vec4& color) {
  shader_.Bind();

  shader_.Unbind();
}

}  // namespace arc
