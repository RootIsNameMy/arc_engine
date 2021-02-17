
//
// Created by adolin on 23. 12. 20.
//

#ifndef ARC_ENGINE_PERSPECTIVE_CAMERA_H
#define ARC_ENGINE_PERSPECTIVE_CAMERA_H

#include <glm.hpp>
namespace arc {
class PerspectiveCamera {
 public:
  void Setup(float screen_ratio, float zoom = 10, float z_near = -100,
             float z_far = 100, const glm::vec3& position = {0, 0, 10},
             const glm::vec3& rotation = {0,0,0});

  void SetView(const glm::vec3& position, const glm::vec3& rotation);
  void SetProjection(float fov, float screen_ratio, float z_near = -100,
                     float z_far = 100);

  const glm::mat4& view() const { return view_; }
  const glm::mat4& projection() const { return projection_; }
  const glm::mat4& view_projection() const { return view_projection_; }

 private:
  glm::mat4 view_;
  glm::mat4 projection_;
  glm::mat4 view_projection_;
};
}  // namespace arc

#endif  // ARC_ENGINE_PERSPECTIVE_CAMERA_H
