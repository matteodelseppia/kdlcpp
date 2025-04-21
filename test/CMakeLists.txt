#####################################
# Fetch Google Test
#####################################

set(KDLCPP_GTEST_VERSION "v1.16.0")

message(STATUS "gtest version: ${KDLCPP_GTEST_VERSION}")

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG ${KDLCPP_GTEST_VERSION}
)

FetchContent_MakeAvailable(googletest)
include(GoogleTest)


#####################################
# Setup testing target
#####################################

set(TARGET_NAME ${PROJECT_NAME}_tests)

set(KDLCPP_TEST_SOURCES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(KDLCPP_TEST_SOURCES
  ${KDLCPP_TEST_SOURCES_DIR}/value_tests.cpp
  ${KDLCPP_TEST_SOURCES_DIR}/stream_tests.cpp
)

set(ALL_FILES ${KDLCPP_TEST_SOURCES})

source_group("Source Files" FILES ${KDLCPP_TEST_SOURCES})

add_executable(${TARGET_NAME} ${ALL_FILES})

get_target_property(PROJECT_INCLUDE_DIRECTORIES ${PROJECT_NAME} INCLUDE_DIRECTORIES)
#get_target_property(PROJECT_LINK_LIBRARIES ${PROJECT_NAME} LINK_LIBRARIES)

target_include_directories(
  ${TARGET_NAME}
    PRIVATE
      ${PROJECT_INCLUDE_DIRECTORIES})

target_link_libraries(
  ${TARGET_NAME}
    PRIVATE
      gtest_main
      ${PROJECT_NAME}
      #${PROJECT_LINK_LIBRARIES}
)

enable_testing()
gtest_discover_tests(${TARGET_NAME})