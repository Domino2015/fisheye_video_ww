cmake_minimum_required(VERSION 3.6)
project(fisheye_video_ww)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenCV REQUIRED)

set(SOURCE_FILES main.cpp)
add_executable(fisheye_video_ww ${SOURCE_FILES})

target_link_libraries(fisheye_video_ww ${OpenCV_LIBS} )