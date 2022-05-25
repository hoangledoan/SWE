add_executable(angle_test geometry2d/angle_test.cpp)
add_executable(geo_compare_test geometry2d/geo_compare_test.cpp)
add_executable(line_test geometry2d/line_test.cpp)
add_executable(point_test geometry2d/point_test.cpp)
add_executable(pose_test geometry2d/pose_test.cpp)

target_link_libraries(angle_test PRIVATE angle_lib)
target_link_libraries(geo_compare_test PRIVATE geo_compare_lib)
target_link_libraries(line_test PRIVATE line_lib)
target_link_libraries(point_test PRIVATE point_lib)
target_link_libraries(pose_test PRIVATE pose_lib)

