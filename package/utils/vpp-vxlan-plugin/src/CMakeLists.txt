CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
project(vpp-vxlan-plugin C)

include(CompileOptions.cmake)

set(PLUGIN 0 CACHE BOOL "Build a plugin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

include_directories(${CMAKE_SOURCE_DIR}/src/)

set(SOURCES
    vpp_vxlan.c
  )

if(PLUGIN)
	add_library(${CMAKE_PROJECT_NAME} MODULE ${SOURCES})
	install(TARGETS ${CMAKE_PROJECT_NAME} DESTINATION lib)
else()
	add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})
	install(TARGETS ${CMAKE_PROJECT_NAME} DESTINATION bin)
endif()

set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES OUTPUT_NAME ${CMAKE_PROJECT_NAME} PREFIX "")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules")
find_package(LibYANG REQUIRED)
find_package(SYSREPO REQUIRED)

target_link_libraries(
	${PROJECT_NAME}
	${LIBYANG_LIBRARIES}
	${SYSREPO_LIBRARIES}
	)

include_directories(
	${LIBYANG_INCLUDE_DIRS}
	${SYSREPO_INCLUDE_DIRS}
	)


