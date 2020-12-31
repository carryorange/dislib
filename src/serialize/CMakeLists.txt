set(DRIVER_EXEC serializer_driver)

add_executable(${DRIVER_EXEC} serializer_driver.cpp)
install(TARGETS ${DRIVER_EXEC} DESTINATION "${CMAKE_INSTALL_PREFIX}/bin")