cmake_minimum_required(VERSION 2.8)

find_package(OpenCV REQUIRED)
set(CMAKE_CXX_FLAGS "-g -Wall")

project(TransFiltersTrans)
#add_executable(trans trans)
#target_link_libraries(trans ${OpenCV_LIBS})
#SET_TARGET_PROPERTIES(trans PROPERTIES LINKER_LANGUAGE CXX)

project(TransFiltersBlur)
add_executable(blur blur)
target_link_libraries(blur ${OpenCV_LIBS})
SET_TARGET_PROPERTIES(blur PROPERTIES LINKER_LANGUAGE CXX)

project(TransFiltersDilate)
add_executable(dilate dilate)
target_link_libraries(dilate ${OpenCV_LIBS})
SET_TARGET_PROPERTIES(dilate PROPERTIES LINKER_LANGUAGE CXX)

project(TransFiltersErode)
add_executable(erode erode)
target_link_libraries(erode ${OpenCV_LIBS})
SET_TARGET_PROPERTIES(erode PROPERTIES LINKER_LANGUAGE CXX)

project(TransFiltersConvolve)
add_executable(convolve convolve)
target_link_libraries(convolve ${OpenCV_LIBS})
SET_TARGET_PROPERTIES(convolve PROPERTIES LINKER_LANGUAGE CXX)

project(TransFiltersAffine)
add_executable(affine affine)
target_link_libraries(affine ${OpenCV_LIBS})
SET_TARGET_PROPERTIES(affine PROPERTIES LINKER_LANGUAGE CXX)

project(TransFiltersPerspective)
add_executable(perspective perspective)
target_link_libraries(perspective ${OpenCV_LIBS})
SET_TARGET_PROPERTIES(perspective PROPERTIES LINKER_LANGUAGE CXX)



