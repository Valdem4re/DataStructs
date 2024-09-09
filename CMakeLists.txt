cmake_minimum_required(VERSION 3.5)

project(DataStructs)

add_subdirectory(
    ListObject
    OneLinkedList
)

add_executable(${PROJECT_NAME}
 main.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    ListObject
    OneLinkedList
)

target_include_directories(${PROJECT_NAME} PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/OneLinkedList
    ${CMAKE_CURRENT_SOURCE_DIR}/ListObject
)