#include <gtest/gtest.h>
#include <sstream>

#include "kdlcpp/value.hpp"
#include "kdlcpp/stream.hpp"
#include "kdlcpp/detail/serialize.hpp"

using namespace kdlcpp;
using namespace kdlcpp::detail;
using namespace kdlcpp::detail::serialize;

TEST(serialize_value, serializes_string_value) {
  value val{"hello"};
  std::stringstream ss;
  stream<std::stringstream> out{std::move(ss)};
  serialize_value(out, val);
  EXPECT_EQ(out.get().str(), "\"hello\"");
}

TEST(serialize_value, serializes_integral_value) {
  value val{12345};
  std::stringstream ss;
  stream<std::stringstream> out{std::move(ss)};
  serialize_value(out, val);
  EXPECT_EQ(out.get().str(), "12345");
}

TEST(serialize_value, serializes_decimal_value) {
  value val{3.1415};
  std::stringstream ss;
  stream<std::stringstream> out{std::move(ss)};
  serialize_value(out, val);
  EXPECT_EQ(out.get().str(), "3.1415");
}

TEST(serialize_value, serializes_boolean_true_value) {
  value val{true};
  std::stringstream ss;
  stream<std::stringstream> out{std::move(ss)};
  serialize_value(out, val);
  EXPECT_EQ(out.get().str(), tokens::$true);
}

TEST(serialize_value, serializes_boolean_false_value) {
  value val{false};
  std::stringstream ss;
  stream<std::stringstream> out{std::move(ss)};
  serialize_value(out, val);
  EXPECT_EQ(out.get().str(), tokens::$false);
}

TEST(serialize_value, serializes_null_value) {
  value val;  // default is null
  std::stringstream ss;
  stream<std::stringstream> out{std::move(ss)};
  serialize_value(out, val);
  EXPECT_EQ(out.get().str(), tokens::$null);
}

