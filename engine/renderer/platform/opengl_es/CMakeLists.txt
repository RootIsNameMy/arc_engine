cmake_minimum_required(VERSION 3.17)

include("project-meta-info.in")



project(
        ArcOpenGLES
        VERSION ${project_version}
        DESCRIPTION ${project_description}
        HOMEPAGE_URL ${project_homepage}
        LANGUAGES CXX C
)

add_library(arc_opengl_es OBJECT)

target_sources(arc_opengl_es
        PUBLIC
            src/opengl_es_context.cpp
            src/opengl_es_texture.cpp
            src/opengl_es_buffer.cpp
            src/opengl_es_renderer_api.cpp
            src/opengl_es_shader.cpp
            src/opengl_es_vertex_array.cpp
        )
target_link_libraries(arc_opengl_es PUBLIC SDL2 arc_log)

target_include_directories(arc_opengl_es PUBLIC include)
