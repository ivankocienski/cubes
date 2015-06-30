#set(CMAKE_VERBOSE_MAKEFILE ON)
# our exe name
project (cubes)

cmake_minimum_required (VERSION 2.8)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -g")

find_package(OpenGL REQUIRED)

# GLFW crap
find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)

find_package (PNG REQUIRED)

# source files. sure, there's a better way of doing this
set (SRC
  src/main.cc
  src/axis-animator.cc
  src/camera.cc
  src/cube-grid.cc
  src/position-animator.cc
  src/quaternion.cc
  src/scene.cc
  src/vector3.cc
  )

include_directories(${GLFW_INCLUDE_DIRS})

link_libraries(
  ${GLFW_LIBRARIES}
  ${OPENGL_LIBRARIES}
  ${PNG_LIBRARIES}
  )

add_executable(cubes ${SRC} )

add_custom_command(TARGET cubes POST_BUILD
  COMMAND rm -f ${CMAKE_CURRENT_BINARY_DIR}/data COMMENT "removing stale data directory"
  COMMAND ln -sf ${CMAKE_SOURCE_DIR}/data ${CMAKE_CURRENT_BINARY_DIR}/data COMMENT "linking data directory"
  )
