message(STATUS "CMAKE_BINARY_DIR=${CMAKE_BINARY_DIR}")
set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}) # TODO: Need general install dir

set(UTIL_LIB lib_utils)
set(TREES_LIB lib_trees)
set(UFDS_LIB lib_union_find_disjoint_set)

add_subdirectory(utils)
add_subdirectory(trees)
add_subdirectory(union_set)
add_subdirectory(serialize)