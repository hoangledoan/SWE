add_library(angle_lib src/angle.cpp)
add_library(geo_compare_lib src/geo_compare.cpp)
add_library(line_lib src/line.cpp)
add_library(point_lib src/point.cpp)
add_library(pose_lib src/pose.cpp)

target_include_directories(angle_lib PUBLIC include)
target_include_directories(geo_compare_lib PUBLIC include)
target_include_directories(line_lib PUBLIC include)
target_include_directories(point_lib PUBLIC include)
target_include_directories(pose_lib PUBLIC include)

target_link_libraries(geo_compare_lib PUBLIC compare)
