add_library(Exceptions
    Exceptions.h
    Exceptions.cpp
)

target_include_directories(Exceptions PUBLIC ${SMAKE_CURRENT_SOURCE_DIR})