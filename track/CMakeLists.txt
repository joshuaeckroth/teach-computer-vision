cmake_minimum_required(VERSION 2.8)
find_package(OpenCV REQUIRED)
set(CMAKE_CXX_FLAGS "-g -Wall")

project(TrackTracker)
add_executable(track track)
target_link_libraries(track ${OpenCV_LIBS})
SET_TARGET_PROPERTIES(track PROPERTIES LINKER_LANGUAGE CXX)

project(TrackBGSub)
add_executable(bgsub bgsub)
target_link_libraries(bgsub ${OpenCV_LIBS})
SET_TARGET_PROPERTIES(bgsub PROPERTIES LINKER_LANGUAGE CXX)

project(TrackBGSubMOG)
add_executable(bgsubmog bgsubmog)
target_link_libraries(bgsubmog ${OpenCV_LIBS})
SET_TARGET_PROPERTIES(bgsubmog PROPERTIES LINKER_LANGUAGE CXX)
