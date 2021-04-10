cmake_minimum_required(VERSION 3.0.0)
project(Card_Game VERSION 0.1.0)
set (CMAKE_CXX_STANDARD 11)

find_package(OpenGL REQUIRED)
find_package(glm REQUIRED)
find_package(glfw3 3.3 REQUIRED)

include_directories(./include)

file(GLOB SOURCES "src/*.cpp" "src/animations/*.cpp" "src/third_parties/**.c")
add_executable(Card_Game ${SOURCES})

add_library(libs ${libs} "src/stb_image.cpp")

file(GLOB LIBRARIES "lib/*.dylib")
message("LIBRARIES = ${LIBRARIES}")

target_link_libraries(Card_Game
    OpenGL::GL
    glfw
    ${LIBRARIES}
    ${libs}
)