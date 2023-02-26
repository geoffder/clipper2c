cmake_minimum_required(VERSION 3.18)
project(clipper2c LANGUAGES CXX)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CLIPPER2_UTILS OFF)
set(CLIPPER2_EXAMPLES OFF)
set(CLIPPER2_TESTS OFF)
# disable exceptions
add_definitions(-D_HAS_EXCEPTIONS=0) # for STL

option(BUILD_SHARED_LIBS OFF)
add_compile_options(-fPIC)

add_subdirectory(vendor/Clipper2/CPP)

# Build svg from utils without forced static linking (altered from Clipper2 CMakeLists.txt)

set(CLIPPER2_SVG_INC
  vendor/Clipper2/CPP/Utils/clipper.svg.h
)

set(CLIPPER2_SVG_SRC
 vendor/Clipper2/CPP/Utils/clipper.svg.cpp
)

add_library(Clipper2svg ${CLIPPER2_SVG_INC} ${CLIPPER2_SVG_SRC})
target_link_libraries(Clipper2svg PUBLIC Clipper2)

set_target_properties(Clipper2svg PROPERTIES FOLDER Libraries)
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  target_compile_options(Clipper2svg PRIVATE -Wno-unused-variable -Wno-unused-function)
endif()

# C Bindings

file(GLOB_RECURSE SOURCE_FILES  src/*.cpp)

add_library(clipper2c ${SOURCE_FILES})

target_link_libraries(
  clipper2c
  PRIVATE Clipper2 Clipper2svg
)

target_include_directories(clipper2c PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_compile_features(clipper2c PRIVATE cxx_std_17)
