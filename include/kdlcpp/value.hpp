#pragma once

#include "kdlcpp/common.hpp"

#include <variant>
#include <optional>

namespace kdlcpp {

/**
 * @brief Represents a generic value that can be stored within a KDL document.
 * 
 * A value instance can be used either as a node argument or as a node property value.
 * The supported data types are:
 * 
 * - Null        (null equivalent)
 * 
 * - Boolean     (true/false)
 * 
 * - Integral    (64-bit signed integer)
 * 
 * - Decimal     (double-precision floating point)
 * 
 * - String      (UTF-8 encoded text)
 */
class value {
public:
  /**
   * @brief Placeholder type representing a null value.
   */
  struct nulltype {};

  /// Boolean type (true or false).
  using boolean  = bool;

  /// 64-bit signed integer type.
  using integral = std::int64_t;

  /// 64-bit floating point decimal type.
  using decimal  = std::double_t;

  /// UTF-8 encoded string type.
  using string   = string_type;

  /**
   * @brief Enum representing the current type held by the value.
   */
  enum class type {
    null,     // The value is null.
    boolean,  // The value is a boolean.
    integral, // The value is an integer.
    decimal,  // The value is a floating-point number.
    string    // The value is a string.
  };

  /// @brief Default constructor builds a null value.
  value() = default;

  /**
   * Parameterized constructor.
   * @tparam The type of the value.
   * @param val The value to store.
   */
  template <typename T>
  value(const T& val) {
    set(val);
  }

  /**
   * @brief Retrieves the stored value as the requested type.
   *
   * If the actual type stored in the Value does not match the requested type,
   * an empty std::optional is returned.
   * 
   * @tparam T The expected type.
   * @return std::optional<T> containing the value if the types match, or std::nullopt otherwise.
   */
  template <typename T>
  [[nodiscard]] std::optional<T> get() const noexcept {
    if (const auto ptr = std::get_if<T>(&m_content)) {
      return *ptr;
    }
    return std::nullopt;
  }

  /**
   * @brief Returns the type of the currently stored value.
   * 
   * @return type enum representing the value's type.
   */
  [[nodiscard]] type get_type() const noexcept;

  /**
   * @brief Sets the stored value to the specified value.
   * 
   * The type of the provided value must be one of the supported types
   * (nulltype, boolean, integral, decimal, or string).
   * 
   * @tparam T The type of the value being set.
   * @param val The value to store.
   */
  template <typename T>
  void set(const T& val) noexcept {
    m_content = val;
    update_type();
  }

  /**
   * @brief A constant representing a null value.
   * 
   * Can be used to explicitly set the value to null:
   *     value.Set(Value::Null);
   */
  static constexpr nulltype null;

private:
  using content_type = std::variant<nulltype, boolean, integral, decimal, string>;

  void update_type();

  type m_type{type::null};       // Current type of the value.
  content_type m_content{null};  // Underlying value content.
};

} // namespace kdlcpp
