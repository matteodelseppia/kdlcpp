#include <gtest/gtest.h>

#include "kdlcpp/value.hpp"

using namespace kdlcpp;

/**
 * Verifies that a default-initialized value is a null.
 */
TEST(value, default_value_is_null) {
  value val;

  EXPECT_EQ(val.get_type(), value::type::null);

  const auto content = val.get<value::nulltype>();
  static_assert(std::is_same_v<std::decay_t<decltype(*content)>, value::nulltype>);
}

/**
 * Sets a string value as value content and verifies
 * that type and content has been set correctly.
 */
TEST(value, constructor_with_string_param_builds_string_value) {
  const value::string myString = "hello";
  value val{myString};

  EXPECT_EQ(val.get_type(), value::type::string);
  EXPECT_EQ(val.get<value::string>(), myString);
}

/**
 * Sets an integral value as value content and verifies
 * that type and content has been set correctly.
 */
TEST(value, constructor_with_integral_value_builds_integral_value) {
  const value::integral myIntegral = -294942;
  value val{myIntegral};

  EXPECT_EQ(val.get_type(), value::type::integral);
  EXPECT_EQ(val.get<value::integral>(), myIntegral);
}

/**
 * Sets a decimal value as value content and verifies
 * that type and content has been set correctly.
 */
TEST(value, constructor_with_decimal_value_builds_decimal_value) {
  const value::decimal myDecimal = 0.125;
  value val{myDecimal};

  EXPECT_EQ(val.get_type(), value::type::decimal);
  EXPECT_EQ(val.get<value::decimal>(), myDecimal);
}

/**
 * Sets a boolean value as value content and verifies
 * that type and content has been set correctly.
 */
TEST(value, constructor_with_boolean_value_builds_boolean_value) {
  const value::boolean myBoolean = false;
  value val{myBoolean};

  EXPECT_EQ(val.get_type(), value::type::boolean);
  EXPECT_EQ(val.get<value::boolean>(), myBoolean);
}

/**
 * Sets a string value as value content, then sets
 * and verifies the value to be null.
 */
TEST(value, nullify_value) {
  const value::string myString = "hello";
  value val{myString};

  val.set(value::null);
  EXPECT_EQ(val.get_type(), value::type::null);
  const auto content = val.get<value::nulltype>();
  static_assert(std::is_same_v<std::decay_t<decltype(*content)>, value::nulltype>);
}