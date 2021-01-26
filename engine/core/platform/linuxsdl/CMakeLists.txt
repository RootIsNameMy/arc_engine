cmake_minimum_required(VERSION 3.17)

include("project-meta-info.in")



project(
        ArcLinuxSDL
        VERSION ${project_version}
        DESCRIPTION ${project_description}
        HOMEPAGE_URL ${project_homepage}
        LANGUAGES CXX C
)

add_library(arc_linux_sdl OBJECT)
target_sources(arc_linux_sdl
        PUBLIC
        src/platform_window.cpp
        src/platform_input.cpp
        )
target_include_directories(arc_linux_sdl PUBLIC include)
target_link_libraries(arc_linux_sdl PUBLIC arc_log SDL2)