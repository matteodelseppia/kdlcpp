#include <gtest/gtest.h>
#include <sstream>

#include "kdlcpp/stream.hpp"

using namespace kdlcpp;

/**
 * Verifies that the stream writes a string to an underlying stringstream.
 */
TEST(stream, write_string_to_stream) {
  std::stringstream ss;
  stream<std::stringstream> myStream{std::move(ss)};
  const std::string testStr = "Hello, world!";

  myStream.write(testStr);
  EXPECT_EQ(myStream.get().str(), testStr);
}

/**
 * Verifies that the stream writes an integer to an underlying stringstream.
 */
TEST(stream, write_integer_to_stream) {
  std::stringstream ss;
  stream<std::stringstream> myStream{std::move(ss)};
  const int testInt = 42;

  myStream.write(testInt);
  EXPECT_EQ(myStream.get().str(), "42");
}

/**
 * Verifies that the stream supports the << operator.
 */
TEST(stream, stream_insertion_operator) {
  std::stringstream ss;
  stream<std::stringstream> myStream{std::move(ss)};

  myStream << "Test: " << 123 << ", " << 4.56;
  EXPECT_EQ(myStream.get().str(), "Test: 123, 4.56");
}

/**
 * Verifies that get() returns a const reference to the underlying stream.
 */
TEST(stream, get_returns_const_reference) {
  std::stringstream ss;
  stream<std::stringstream> myStream{std::move(ss)};

  myStream.write("const test");
  const auto& internal = myStream.get();

  EXPECT_EQ(internal.str(), "const test");
}