file(GLOB trees_src
    "*.h"
    "*.cpp")

add_library(${TREES_LIB} ${trees_src})
target_link_libraries(${TREES_LIB} ${UTIL_LIB})

target_include_directories(${TREES_LIB} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})