cmake_minimum_required(VERSION 3.17)

include("project-meta-info.in")



project(
        ArcAndroid
        VERSION ${project_version}
        DESCRIPTION ${project_description}
        HOMEPAGE_URL ${project_homepage}
        LANGUAGES CXX C
)

add_library(arc_android OBJECT)
target_sources(arc_android
        PUBLIC
        src/platform_window.cpp
        src/platform_input.cpp
        )
target_include_directories(arc_android PUBLIC include)
target_link_libraries(arc_android PUBLIC arc_log SDL2)