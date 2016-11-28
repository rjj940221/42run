cmake_minimum_required(VERSION 3.6)
project(42run)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g3 -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo")

set(SOURCE_FILES src/main.cpp src/load_shader.cpp src/ogl.cpp src/support.cpp)
add_executable(42run ${SOURCE_FILES})
include_directories(/nfs/zfs-student-6/users/rojones/Documents/42run/Framework/Glfw/include)
include_directories(/nfs/zfs-student-6/users/rojones/Documents/42run/Framework/Glew/include)
include_directories(/nfs/zfs-student-6/users/rojones/Documents/42run/includes)
target_link_libraries(42run /nfs/zfs-student-6/users/rojones/Documents/42run/Framework/Glfw/lib/libglfw3.a)
target_link_libraries(42run /nfs/zfs-student-6/users/rojones/Documents/42run/Framework/Glew/lib/libGLEW.a)