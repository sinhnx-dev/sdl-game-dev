cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_OBJC_COMPILE_OBJECT "")

project(SDL3Game VERSION 1.0.0)
add_executable(SDL3Game src/main.cpp)

add_subdirectory(external/SDL)
add_subdirectory(external/SDL_image)
add_subdirectory(external/SDL_ttf)

target_link_libraries(SDL3Game PRIVATE 
    SDL3::SDL3
    # SDL3_image 
    SDL3_image::SDL3_image
    # SDL3_ttf
    SDL3_ttf::SDL3_ttf
)

target_include_directories(
    SDL3Game PRIVATE
    external/SDL/include
    external/SDL_image/include
    external/SDL_ttf/include
)

if (WIN32)
  target_link_libraries(
    SDL3Game PRIVATE SDL3main
  )
elseif(APPLE)
  message("macOS App")
  enable_language(OBJC)
  set(CMAKE_OSX_ARCHITECTURES "arm64")
endif()