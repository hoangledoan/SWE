add_library(compare src/compare.cpp)
target_include_directories(compare PUBLIC include)
target_link_libraries(compare PUBLIC geo_compare_lib)