add_library(mysrc src/angle.cpp
                  src/geo_compare.cpp
                  src/line.cpp
                  src/point.cpp
                  src/pose.cpp)
                  
target_include_directories(mysrc PUBLIC include)

target_link_libraries(mysrc PUBLIC compare)
