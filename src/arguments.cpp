#include "kdlcpp/arguments.hpp"

namespace kdlcpp {

std::size_t arguments::size() const noexcept {
  return m_arguments_list.size();
}

std::optional<value> arguments::at(const std::size_t index) const noexcept {
  if (index >= m_arguments_list.size())
    return std::nullopt;

  return m_arguments_list.at(index);
}

void arguments::insert_at(const std::size_t index, const value& val) noexcept {
  if (index >= m_arguments_list.size()) {
    m_arguments_list.resize(index + 1);
  }
  m_arguments_list[index] = val;
}

void arguments::push_back(const value& val) noexcept {
  m_arguments_list.push_back(val);
}

bool arguments::erase(const std::size_t index) noexcept {
  if (index >= m_arguments_list.size()) {
    return false;
  }

  m_arguments_list.erase(m_arguments_list.begin() + index);
  return true;
}

} // namespace kdlcpp
