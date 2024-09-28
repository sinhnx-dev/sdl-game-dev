cmake_minimum_required(VERSION 3.10)

project(SDL_Win32 VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 14)

if(WIN32)
    set(SDL2_LIB_DIR C:/dev/SDL/lib)
    set(SDL2_LIBRARY C:/dev/SDL/bin)
    set(SDL2_INCLUDE_DIR C:/dev/SDL/include)
    link_directories(${SDL2_LIB_DIR})
endif()

add_executable(${PROJECT_NAME}
    src/main.cpp
)

if(WIN32)
    target_include_directories(${PROJECT_NAME} PUBLIC ${SDL2_INCLUDE_DIR})    
    target_link_libraries(
        ${PROJECT_NAME}
        mingw32
        SDL2main    
        SDL2
        SDL2_image
    )
    file(COPY ${SDL2_LIBRARY}/SDL2.dll DESTINATION ./)
    file(COPY ${SDL2_LIBRARY}/SDL2_image.dll DESTINATION ./)
else()
    target_link_libraries(${PROJECT_NAME} PUBLIC ${SDL2_LIB} SDL2_image::SDL2_image)
endif()



# Copy file
file(COPY res DESTINATION ./)