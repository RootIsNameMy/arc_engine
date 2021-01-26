cmake_minimum_required(VERSION 3.17)

include("project-meta-info.in")



project(
        ArcLinux
        VERSION ${project_version}
        DESCRIPTION ${project_description}
        HOMEPAGE_URL ${project_homepage}
        LANGUAGES CXX C
)

add_library(arc_linux OBJECT)
target_sources(arc_linux
        PUBLIC
        src/platform_input.cpp
        src/platform_window.cpp
        )
target_include_directories(arc_linux PUBLIC include)
target_link_libraries(arc_linux PUBLIC arc_log glfw)