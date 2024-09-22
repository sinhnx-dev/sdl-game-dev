cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_OBJC_COMPILE_OBJECT "")

project(SDL2Game VERSION 1.0.0)
add_executable(${PROJECT_NAME} src/main.cpp)

add_subdirectory(external/SDL)
add_subdirectory(external/SDL_image)
add_subdirectory(external/SDL_ttf)

target_link_libraries(${PROJECT_NAME} PRIVATE 
    SDL2::SDL2
    SDL2_image::SDL2_image
    SDL2_ttf::SDL2_ttf
)

target_include_directories(
    ${PROJECT_NAME} PRIVATE
    external/SDL/include
    external/SDL_image/include
    external/SDL_ttf/include
)

if (WIN32)
  target_link_libraries(
    ${PROJECT_NAME} PRIVATE SDL2 SDL2_image SDL2_ttf
  )
elseif(APPLE)
  message("macOS App")
  set(CMAKE_OSX_ARCHITECTURES "arm64")
endif()

# Copy file
file(COPY assets DESTINATION ./)