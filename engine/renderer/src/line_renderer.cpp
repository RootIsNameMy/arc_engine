
//
// Created by adolin on 23. 12. 20.
//

#include "line_renderer.h"

#include <engine.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/rotate_vector.hpp>

#include "renderer_api.h"
namespace arc {
static const int s_maxNumLines = 10000;
void LineRenderer::Init() {
  vertex_array_.Create();

  vertex_buffer_.Create(s_maxNumLines * 2 * sizeof(LineVertex));
  vertex_buffer_.set_layout({
      {ShaderDataType::Float3, "a_position"},
      {ShaderDataType::Float4, "a_color"},
  });

  vertex_array_.AddVertexBuffer(vertex_buffer_);

  vertices_ = new LineVertex[s_maxNumLines * 2];

  indices_ = new uint[s_maxNumLines * 6];

  for (int i = 0; i < s_maxNumLines * 2; ++i) {
    indices_[i] = i;
  }

  index_buffer_.Create(indices_, s_maxNumLines * 2);
  vertex_array_.set_index_buffer(index_buffer_);

  // shader_.Create("/home/martines/Desktop/git_repos/arc_engine/engine/shaders/2d_shader");
  shader_.Create(
      "/home/tilen/Projects/feri/URG/vaja01/arc_engine/engine/shaders/"
      "debug_shader");
}

void LineRenderer::Destroy() {
  delete[] indices_;
  delete[] vertices_;
}

void LineRenderer::Begin(const OrthographicCamera &camera) {
  shader_.Bind();
  shader_.SetMat4("u_view_projection", camera.view_projection());
  shader_.Unbind();

  //        shader_text_.Bind();
  //        shader_text_.SetMat4("u_projection",glm::ortho(0.0f,
  //        (float)Engine::window().width(), 0.0f,
  //        (float)Engine::window().height()));
  //        shader_text_.SetFloat4("u_color",{1,1,1,1});
  //        shader_text_.Unbind();
  num_lines_ = 0;
}

void LineRenderer::End() { Flush(); }

void LineRenderer::Flush() {
  shader_.Bind();
  vertex_array_.Bind();
  RenderCommand::SetDrawType(DrawType::Line);
  vertex_buffer_.SetData(vertices_, num_lines_ * 2 * sizeof(LineVertex));
  vertex_array_.set_index_buffer(index_buffer_);
  RenderCommand::DrawIndexed(vertex_array_, num_lines_ * 2);

  vertex_array_.Unbind();
  shader_.Unbind();

  num_lines_ = 0;
}

void LineRenderer::DrawLine(const glm::vec3 &a, const glm::vec3 &b,
                            const glm::vec4 &color) {
  if (num_lines_ == s_maxNumLines) return;
  vertices_[num_lines_ * 2].pos = a;
  vertices_[num_lines_ * 2].color = color;
  vertices_[num_lines_ * 2 + 1].pos = b;
  vertices_[num_lines_ * 2 + 1].color = color;
  num_lines_++;
}
}  // namespace arc
