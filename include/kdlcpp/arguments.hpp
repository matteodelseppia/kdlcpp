#pragma once

#include "kdlcpp/value.hpp"

#include <vector>

namespace kdlcpp {

/**
 * In KDL, a node can have arguments. Arguments are a list
 * of unnamed values passed in a specific order. Each argument
 * is a kdlcpp::value and the order in which they are stored
 * is significant. arguments are always relative to a single node.
 */
class arguments {
public:

  /**
   * Returns an iterator to the beginning of the arguments list.
   */
  [[nodiscard]] inline auto begin() noexcept {
    return m_arguments_list.begin();
  }

  /**
   * Returns a const iterator to the beginning of the arguments list.
   */
  [[nodiscard]] inline auto begin() const noexcept {
    return m_arguments_list.cbegin();
  }

  /**
   * Returns an iterator to the end of the arguments list.
   */
  [[nodiscard]] inline auto end() noexcept {
    return m_arguments_list.end();
  }

  /**
   * Returns a const iterator to the end of the arguments list.
   */
  [[nodiscard]] inline auto end() const noexcept {
    return m_arguments_list.cend();
  }

  /**
   * Returns the number of arguments currently stored.
   * @return The number of arguments.
   */
  [[nodiscard]] std::size_t size() const noexcept;

  /**
   * Gets the kdlcpp::value at a specific index.
   * @param index The index of the argument.
   * @return A kdlcpp::Value instance if it exists.
   */
  [[nodiscard]] std::optional<value> at(const std::size_t index) const noexcept;

  /**
   * Sets the argument at a specific index to the given value.
   * If the index is beyond the current size, the vector is resized
   * and intermediate elements are default-initialized.
   * @param index The index to set.
   * @param val The value to assign.
   */
  void insert_at(const std::size_t index, const value& val) noexcept;

  /**
   * Appends a new argument at the end of the argument list.
   * @param val The value to append.
   */
  void push_back(const value& val) noexcept;

  /**
   * Removes the argument at the specified index.
   * @param index The index of the argument to remove.
   * @return false if the index was out of range, true otherwise.
   */
  bool erase(const std::size_t index) noexcept;

private:
  /// The growable, ordered list of arguments.
  std::vector<value> m_arguments_list;
};

} // namespace kdlcpp
