cmake_minimum_required(VERSION 3.17)

include("${CMAKE_CURRENT_LIST_DIR}/project-meta-info.in")



project(
        ArcCore
        VERSION ${project_version}
        DESCRIPTION ${project_description}
        HOMEPAGE_URL ${project_homepage}
        LANGUAGES CXX C
)

add_library(arc_core OBJECT include/functions.h)
target_sources(arc_core
        PUBLIC
            src/engine.cpp
            src/event_handler.cpp
            src/window.cpp


        )

if (ARC_PLATFORM_ANDROID)

    if(ARC_PLATFORM_SDL)
        add_subdirectory(platform/android)
        target_include_directories(arc_android PUBLIC ${INCLUDES})
        target_link_libraries(arc_core PUBLIC arc_android GLESv3)
        target_include_directories(arc_core PUBLIC platform/android/include)
    else()
        message(FATAL_ERROR "Not supported!")
    endif()

elseif (ARC_PLATFORM_LINUX)
    if(ARC_PLATFORM_GLFW)
        add_subdirectory(platform/linux)
        target_include_directories(arc_linux PUBLIC ${INCLUDES} )
        target_link_libraries(arc_core PUBLIC arc_linux )
        target_include_directories(arc_core PUBLIC platform/linux/include)
    elseif(ARC_PLATFORM_SDL)
        add_subdirectory(platform/linuxsdl)
        target_include_directories(arc_linux_sdl PUBLIC ${INCLUDES} )
        target_link_libraries(arc_core PUBLIC arc_linux_sdl)
        target_include_directories(arc_core PUBLIC platform/linuxsdl/include)
    else()
        message(FATAL_ERROR "Not supported!")
    endif()
else()
    message(FATAL_ERROR "Not supported!")
endif ()

target_link_libraries(arc_core PUBLIC arc_log)






