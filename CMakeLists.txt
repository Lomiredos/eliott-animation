cmake_minimum_required(VERSION 3.20)
project(eliott-animation VERSION 1.0.0 LANGUAGES CXX)

if(TARGET eliott-animation)
    return()
endif()
if (PROJECT_IS_TOP_LEVEL)
set(CMAKE_TOOLCHAIN_FILE "C:/Dev/vcpkg/scripts/buildsystems/vcpkg.cmake")
set(CMAKE_PREFIX_PATH "C:/Dev/vcpkg/installed/x64-mingw-static")
endif()

set(CMAKE_CXX_USE_RESPONSE_FILE_FOR_INCLUDES OFF)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(nlohmann_json CONFIG REQUIRED)

add_library(eliott-animation STATIC
    src/AnimationParser.cpp
    src/AnimationSystem.cpp
)

target_include_directories(eliott-animation PUBLIC
    include/
)

target_link_libraries(eliott-animation PUBLIC
    eliott-ecs
    eliott-math
    eliott-renderer
)

target_link_libraries(eliott-animation PRIVATE
    nlohmann_json::nlohmann_json
)
