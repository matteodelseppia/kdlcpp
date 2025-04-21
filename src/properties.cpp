#include "kdlcpp/properties.hpp"

namespace kdlcpp {

auto properties::begin() noexcept { 
  return m_properties_map.begin(); 
}

auto properties::begin() const noexcept { 
  return m_properties_map.cbegin(); 
}

auto properties::end() noexcept { 
  return m_properties_map.end(); 
}

auto properties::end() const noexcept { 
  return m_properties_map.cend(); 
}

std::size_t properties::size() const noexcept {
  return m_properties_map.size();
}

bool properties::contains(const string_type& key) const noexcept {
  return m_properties_map.find(key) != m_properties_map.cend();
}

std::optional<value> properties::at(const string_type& key) const noexcept {
  if (!contains(key))
    return std::nullopt;
  return m_properties_map.at(key);
}

void properties::insert(const string_type& key, const value& val) noexcept {
  m_properties_map.insert_or_assign(key, val);
}

bool properties::erase(const string_type& key) noexcept {
  if (!contains(key))
    return false;
  
  m_properties_map.erase(key);
  return true;
}

} // namespace kdlcpp