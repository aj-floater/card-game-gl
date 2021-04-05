cmake_minimum_required(VERSION 3.0.0)
project(Card_Game VERSION 0.1.0)
set (CMAKE_CXX_STANDARD 11)

find_package(OpenGL REQUIRED)
find_package(glm REQUIRED)
find_package(glfw3 3.3 REQUIRED)

include_directories(./include)

file(GLOB SOURCES "src/*.cpp" "src/*.c")
add_executable(Card_Game ${SOURCES})
file(GLOB LIBRARIES "lib/*.dylib")
message("LIBRARIES = ${LIBRARIES}")

# external resources    --------------------------------------------
file(GLOB GLSL_FILES "shaders/*.glsl")
file(COPY ${GLSL_FILES} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

file(GLOB AUDIO_FILES "audio/*.wav" "audio/*.m4a")
file(COPY ${AUDIO_FILES} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

file(GLOB IMAGE_FILES "images/*.png" "images/*.jpg")
file(COPY ${IMAGE_FILES} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(Card_Game
    OpenGL::GL
    glfw
    ${LIBRARIES}
)