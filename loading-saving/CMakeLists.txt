cmake_minimum_required(VERSION 2.8)

find_package(OpenCV REQUIRED)
set(CMAKE_CXX_FLAGS "-g -Wall")

project(LoadingSavingVideos)
add_executable(videos videos)
target_link_libraries(videos ${OpenCV_LIBS})
SET_TARGET_PROPERTIES(videos PROPERTIES LINKER_LANGUAGE CXX)

project(LoadingSavingImages)
add_executable(images images)
target_link_libraries(images ${OpenCV_LIBS})
SET_TARGET_PROPERTIES(images PROPERTIES LINKER_LANGUAGE CXX)




