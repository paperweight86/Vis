cmake_minimum_required(VERSION 3.0.0)
project(Vis VERSION 0.1.0)

include(CTest)
enable_testing()

add_compile_options(-msse4.1)
add_definitions(-DLINUX)

file(GLOB_RECURSE myApp_SOURCES *.cpp)
add_library(Vis ${myApp_SOURCES})

file(GLOB_RECURSE myApp_INCLUDES *.h)
target_include_directories(Vis 
PRIVATE 
  ./
  gl
  ../Tat/inc
PUBLIC
  inc
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
