#####################################
# kdlcpp general info
#####################################

cmake_minimum_required(VERSION 3.17 FATAL_ERROR)

project(kdlcpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(KDLCPP_VERSION_MAJOR 0)
set(KDLCPP_VERSION_MINOR 1)
set(KDLCPP_VERSION_PATCH 0)

set(CMAKE_KDLCPP_VERSION ${KDLCPP_VERSION_MAJOR}.${KDLCPP_VERSION_MINOR}.${KDLCPP_VERSION_PATCH})

message(STATUS "kdlcpp version: ${CMAKE_KDLCPP_VERSION}")


#####################################
# cmake options
#####################################

option(KDLCPP_BUILD_TESTING "Build kdlcpp tests" OFF)


#####################################
# Add cppLog target library
#####################################

set(KDLCPP_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(KDLCPP_SOURCES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(KDLCPP_HEADERS
  ${KDLCPP_INCLUDE_DIR}/${PROJECT_NAME}/value.hpp
  ${KDLCPP_INCLUDE_DIR}/${PROJECT_NAME}/properties.hpp
  ${KDLCPP_INCLUDE_DIR}/${PROJECT_NAME}/arguments.hpp
  ${KDLCPP_INCLUDE_DIR}/${PROJECT_NAME}/node.hpp
  ${KDLCPP_INCLUDE_DIR}/${PROJECT_NAME}/document.hpp
  ${KDLCPP_INCLUDE_DIR}/${PROJECT_NAME}/common.hpp
  ${KDLCPP_INCLUDE_DIR}/${PROJECT_NAME}/stream.hpp
)

set(KDLCPP_SOURCES
  ${KDLCPP_SOURCES_DIR}/value.cpp
  ${KDLCPP_SOURCES_DIR}/properties.cpp
  ${KDLCPP_SOURCES_DIR}/arguments.cpp
  ${KDLCPP_SOURCES_DIR}/node.cpp
  ${KDLCPP_SOURCES_DIR}/document.cpp
)

set(ALL_FILES ${KDLCPP_HEADERS} ${KDLCPP_SOURCES})

source_group("Header Files" FILES ${KDLCPP_HEADERS})
source_group("Source Files" FILES ${KDLCPP_SOURCES})

add_library(${PROJECT_NAME} ${ALL_FILES})

target_compile_definitions(
  ${PROJECT_NAME}
    PUBLIC
      KDLCPP_VERSION=${CMAKE_KDLCPP_VERSION}
)

target_include_directories(${PROJECT_NAME}
  PUBLIC
    $<BUILD_INTERFACE:${KDLCPP_INCLUDE_DIR}>
)

#####################################
# Configure tests if flag is ON
#####################################

if(KDLCPP_BUILD_TESTING)
  message(STATUS "Compiling kdlcpp unit tests...")
  add_subdirectory(test)
endif()