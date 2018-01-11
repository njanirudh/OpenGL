cmake_minimum_required(VERSION 2.8)

set (CMAKE_CXX_STANDARD 11)


set(SYS_INCLUDE_PATH "/usr/include/linux-x86_64")
set(SYS_LIBRARIES_PATH "/usr/lib/x86_64-linux-gnu")
set(SYS_LINK_LIBRARIES "-lglut -lGLU -lGL -lX11")

include_directories(${SYS_INCLUDE_PATH})
link_directories(${SYS_LINK_LIBRARIES})

file(GLOB IPS_PROJECT_SOURCE_FILES "*.h" "*.cpp")

project(OpenGL-Camera)
add_executable(${PROJECT_NAME} "main.cpp")
target_link_libraries(${PROJECT_NAME} ${SYS_LINK_LIBRARIES} -lpthread -ldl)
