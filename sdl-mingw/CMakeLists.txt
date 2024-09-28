cmake_minimum_required(VERSION 3.10)

project(SDL_MinGW)

add_executable(${PROJECT_NAME}
    src/main.cpp
)

if(NOT PNG AND WIN32 AND NOT MSVC)
    set(PNG_LIBRARY "C:/Program Files(x86)/libpng")
    set(PNG_PNG_INCLUDE_DIR "C:/Program Files(x86)/libpng/include")
endif()

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

target_include_directories(${PROJECT_NAME}
    PUBLIC ${SDL2_INCLUDE_DIRS}
    PUBLIC ${SDL2IMAGE_INCLUDE_DIRS}
)

if(WIN32 AND NOT MSVC)
    message(${SDL2_LIBRARIES})
    target_link_libraries(${PROJECT_NAME} PUBLIC ${SDL2_LIBRARIES} SDL2_image::SDL2_image mingw32)
    file(COPY "C:/Program Files (x86)/SDL2/bin/SDL2.dll" DESTINATION ./)
    file(COPY "C:/Program Files (x86)/SDL2_image/bin/SDL2_image.dll" DESTINATION ./)
else()
    target_link_libraries(${PROJECT_NAME} PUBLIC ${SDL2_LIBRARIES} SDL2_image::SDL2_image)
endif()

# Copy file
file(COPY res DESTINATION ./)