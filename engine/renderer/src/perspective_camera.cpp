
//
// Created by adolin on 23. 12. 20.
//
#include "perspective_camera.h"

#include <gtc/matrix_transform.hpp>

namespace arc {

void PerspectiveCamera::Setup(float screen_ratio, float zoom, float z_near,
                              float z_far, const glm::vec3& position,
                              const glm::vec3& rotation) {
  SetView(position, rotation);
  SetProjection(screen_ratio, zoom, z_near, z_far);
}

void PerspectiveCamera::SetView(const glm::vec3& position,
                                const glm::vec3& rotation) {

  view_ = glm::translate(glm::mat4(1), position);
  for (int i = 0; i < 3; ++i) {
    view_ = glm::inverse(glm::rotate(view_, rotation[i], {i == 0, i == 1, i == 2}));
  }

  view_projection_ = projection_ * view_;
}

void PerspectiveCamera::SetProjection( float fov,float screen_ratio,
                                      float z_near, float z_far) {
  projection_ = glm::perspective(fov, screen_ratio, -100.0f, 100.0f);
  view_projection_ = projection_ * view_;
}
}  // namespace arc
