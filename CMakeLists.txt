cmake_minimum_required(VERSION 3.6)
project(42run)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g3 -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo")

set(SOURCE_FILES src/main.cpp src/load_shader.cpp src/ogl.cpp src/support.cpp src/obj_loader.cpp src/player.cpp includes/player.h src/room.cpp includes/room.h src/obstical.cpp includes/obstical.h)
add_executable(42run ${SOURCE_FILES})

include_directories(${CMAKE_SOURCE_DIR}/Framework/Glfw/include)
include_directories(${CMAKE_SOURCE_DIR}/Framework/Glew/include)
include_directories(${CMAKE_SOURCE_DIR}/Framework/glm/include)
include_directories(${CMAKE_SOURCE_DIR}/includes)
target_link_libraries(42run ${CMAKE_SOURCE_DIR}/Framework/Glfw/lib/libglfw3.a)
target_link_libraries(42run ${CMAKE_SOURCE_DIR}/Framework/Glew/lib/libGLEW.a)
