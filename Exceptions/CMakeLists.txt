add_library(Exceptions
    LinkedListIndexError.h
    LinkedListIndexError.cpp
)

target_include_directories(Exceptions PUBLIC ${SMAKE_CURRENT_SOURCE_DIR})