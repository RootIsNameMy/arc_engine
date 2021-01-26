cmake_minimum_required(VERSION 3.17)

include("project-meta-info.in")

project(
        imgui
        VERSION ${project_version}
        DESCRIPTION ${project_description}
        HOMEPAGE_URL ${project_homepage}
        LANGUAGES CXX C
)


add_library(imgui OBJECT)

if(ARC_PLATFORM_GLFW)
    target_sources(imgui PUBLIC imgui/backends/imgui_impl_glfw.cpp)
elseif(ARC_PLATFORM_SDL)
    target_sources(imgui PUBLIC imgui/backends/imgui_impl_sdl.cpp)
else()
    message(FATAL_ERROR "Not supported!")
endif()

if(ARC_PLATFORM_OPENGL)
    add_compile_definitions(IMGUI_IMPL_OPENGL_LOADER_GLAD) #TODO: doestn actualy work
    target_sources(imgui PUBLIC imgui/backends/imgui_impl_opengl3.cpp)
elseif(ARC_PLATFORM_OPENGL_ES)
    add_compile_definitions(IMGUI_IMPL_OPENGL_LOADER_GLAD)
    target_sources(imgui PUBLIC imgui/backends/imgui_impl_opengl3.cpp)
else()
    message(FATAL_ERROR "Not supported!")
endif()


target_sources(imgui
        PUBLIC
        imgui/imgui_draw.cpp
        imgui/imgui_widgets.cpp
        imgui/imgui_tables.cpp
        imgui/imgui_demo.cpp
        imgui/imgui.cpp)
target_include_directories(imgui PUBLIC imgui imgui/backends)




