file(GLOB util_src
    "*.h"
    "*.cpp")

add_library(${UTIL_LIB} ${util_src})
target_include_directories(${UTIL_LIB} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})