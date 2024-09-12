cmake_minimum_required(VERSION 3.5)

project(DataStructs)

add_subdirectory(ListObject)
add_subdirectory(OneLinkedList)
add_subdirectory(TwoLinkedList)
add_subdirectory(Array)
add_subdirectory(Exceptions)

add_executable(${PROJECT_NAME}
 main.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    ListObject
    OneLinkedList
    TwoLinkedList
    Array
    Exceptions
)

target_include_directories(${PROJECT_NAME} PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/ListObject  
    ${CMAKE_CURRENT_SOURCE_DIR}/OneLinkedList
    ${CMAKE_CURRENT_SOURCE_DIR}/TwoLinkedList
    ${CMAKE_CURRENT_SOURCE_DIR}/Array
    ${CMAKE_CURRENT_SOURCE_DIR}/Exceptions
)