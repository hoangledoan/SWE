add_library(geotest geometry2d/angle_test.cpp
                      geometry2d/geo_compare_test.cpp
                      geometry2d/line_test.cpp
                      geometry2d/point_test.cpp
                      geometry2d/pose_test.cpp)
add_library(utiltest util/compare_test.cpp)

target_link_libraries(geotest PUBLIC mysrc)
target_link_libraries(utiltest PUBLIC compare)