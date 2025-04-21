#pragma once

#include "kdlcpp/value.hpp"

#include <unordered_map>

namespace kdlcpp {

/**
 * In KDL, a node can have Properties. Properties are a set
 * of key-value pairs, or named arguments. Keys are always of
 * kdlcpp::StringType type, while values must be kdlcpp::Value.
 * Properties are always relative to a single node.
 */
class properties {
public:

  /**
   * Returns an iterator to the beginning of the properties map.
   */
  [[nodiscard]] auto begin() noexcept;

  /**
   * Returns a const iterator to the beginning of the properties map.
   */
  [[nodiscard]] auto begin() const noexcept;

  /**
   * Returns an iterator to the end of the properties map.
   */
  [[nodiscard]] auto end() noexcept;

  /**
   * Returns a const iterator to the end of the properties map.
   */
  [[nodiscard]] auto end() const noexcept;

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
   * Gets the kdlcpp::Value associated to a certain key.
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