#pragma once

#include "kdlcpp/value.hpp"

#include <unordered_map>

namespace kdlcpp {

/**
 * In KDL, a node can have Properties. Properties are a set
 * of key-value pairs, or named arguments. Keys are always of
 * kdlcpp::string_type type, while values must be kdlcpp::value.
 * Properties are always relative to a single node.
 */
class properties {
public:

  /**
   * Returns an iterator to the beginning of the properties map.
   */
  [[nodiscard]] inline auto begin() noexcept {
    return m_properties_map.begin();
  }

  /**
   * Returns a const iterator to the beginning of the properties map.
   */
  [[nodiscard]] inline auto begin() const noexcept {
    return m_properties_map.cbegin();
  }

  /**
   * Returns an iterator to the end of the properties map.
   */
  [[nodiscard]] inline auto end() noexcept {
    return m_properties_map.end();
  }

  /**
   * Returns a const iterator to the end of the properties map.
   */
  [[nodiscard]] inline auto end() const noexcept {
    return m_properties_map.cend();
  }

  /**
   * Returns the number of properties currently stored.
   * @return The number of properties.
   */
  [[nodiscard]] std::size_t size() const noexcept;

  /**
   * Checks if a property with a certain key is currently stored
   * in the list of properties.
   * @param key The key of the property to check.
   * @return true if the property with the given key exists, false otherwise.
   */
  [[nodiscard]] bool contains(const string_type& key) const noexcept;

  /**
   * Gets the kdlcpp::value associated to a certain key.
   * @param key The key of the property.
   * @return A kdlcpp:Value instance.
   */
  [[nodiscard]] std::optional<value> at(const string_type& key) const noexcept;

  /**
   * Sets a certain key with a specific kdlcpp::Value. Overwrites the existing
   * property with the same key, if present. 
   * @param key The key of the property to set.
   * @param val The value of the property to be set.
   */
  void insert(const string_type& key, const value& val) noexcept;

  /**
   * Removes a property with a certain key.
   * @param key The key of the property to remove.
   * @return false if the key was not associated to any property, true otherwise.
   */
  bool erase(const string_type& key) noexcept;

private:
  /// Container holding the list of key-value associations.
  std::unordered_map<string_type, value> m_properties_map;
};

} // namespace kdlcpp