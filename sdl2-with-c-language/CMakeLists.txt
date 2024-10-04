cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS OFF)

project(Sdl2_C VERSION 1.0.0)

if(WIN32)
    set(SDL2_LIB_DIR C:/dev/SDL/lib)
    set(SDL2_LIBRARY C:/dev/SDL/bin)
    set(SDL2_INCLUDE_DIR C:/dev/SDL/include/SDL2)
    link_directories(${SDL2_LIB_DIR})
endif()

add_executable(${PROJECT_NAME} src/main.c)

if(WIN32)
  message("Win32 App")
  target_include_directories(${PROJECT_NAME} PUBLIC ${SDL2_INCLUDE_DIR})    
    target_link_libraries(
        ${PROJECT_NAME}
        mingw32
        SDL2main    
        SDL2
    )
    file(COPY ${SDL2_LIBRARY}/SDL2.dll DESTINATION ./)
elseif(APPLE)
  message("macOS App")
  find_package(SDL2 REQUIRED COMPONENTS SDL2)
  target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2)
elseif(UNIX)

endif()