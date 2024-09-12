add_library(Array STATIC Array.h Array.cpp)

target_include_directories(Array PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})