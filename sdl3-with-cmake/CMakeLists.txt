cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 20)

project(SDL3Game VERSION 1.0.0)

add_subdirectory(external/SDL)
# add_subdirectory(external/SDL_image)
# add_subdirectory(external/SDL_ttf)

add_executable(${PROJECT_NAME} src/main.cpp)

target_include_directories(
  ${PROJECT_NAME} PRIVATE
    external/SDL/include
    # external/SDL_image/include
    # external/SDL_ttf/include
)

if (WIN32)
  target_link_libraries(${PROJECT_NAME}
    mingw32    
    # SDL3main
    SDL3
    # SDL3_image
    # SDL_ttf
  )
elseif(APPLE)
  set(CMAKE_OSX_ARCHITECTURES "arm64")
  target_link_libraries(${PROJECT_NAME} PRIVATE 
    SDL3::SDL3
    # SDL3_image::SDL3_image
  )
endif()