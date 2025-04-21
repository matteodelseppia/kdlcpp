#include <gtest/gtest.h>
#include <sstream>

#include "kdlcpp/stream.hpp"

TEST(stream_test, a) {
  std::stringstream ss;
  kdlcpp::stream<std::stringstream> my_stream(ss);

  my_stream << 1 << 2 << 3;
  EXPECT_EQ(ss.str(), "123");
}