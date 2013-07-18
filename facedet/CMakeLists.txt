cmake_minimum_required(VERSION 2.8)

project(FaceDet)
find_package(OpenCV REQUIRED)
add_executable(facedet facedet)
target_link_libraries(facedet ${OpenCV_LIBS})
