file(GLOB ufds_src
    "*.h"
    "*.cpp")

add_library(${UFDS_LIB} ${ufds_src})
target_link_libraries(${UFDS_LIB} ${UTIL_LIB})

target_include_directories(${UFDS_LIB} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})