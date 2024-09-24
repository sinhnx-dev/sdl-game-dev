cmake_minimum_required(VERSION 3.15...3.30)

project(Sdl2WithCMake LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(
  SDL2
  GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
  GIT_TAG release-2.30.x)
FetchContent_Declare(
  SDL2_image
  GIT_REPOSITORY https://github.com/libsdl-org/SDL_image.git
  GIT_TAG release-2.8.x)
# CMake 3.14+
FetchContent_MakeAvailable(SDL2 SDL2_image)

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2 SDL2_image)

# Copy file
file(COPY assets DESTINATION ./)