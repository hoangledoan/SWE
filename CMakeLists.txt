cmake_minimum_required(VERSION 3.16)

include(CTest)
enable_testing()

project(project1)

add_subdirectory(geometry2d)
add_subdirectory(util)
add_subdirectory(test)

target_sources(main PUBLIC test/angle_test.cpp test/geo_compare_test.cpp test/line_test.cpp test/point_test.cpp test/pose_test.cpp)
target_link_libraries(main PRIVATE geometry2d)