#include "kdlcpp/node.hpp"

namespace kdlcpp {

string_type node::get_name() const noexcept {
  return m_name;
}

const arguments& node::get_arguments() const noexcept {
  return m_arguments;
}

const properties& node::get_properties() const noexcept {
  return m_properties;
}

const node_list& node::get_children() const noexcept {
  return m_children;
}

arguments& node::get_arguments() noexcept {
  return m_arguments;
}

properties& node::get_properties() noexcept {
  return m_properties;
}

node_list& node::get_children() noexcept {
  return m_children;
}

} // namespace kdlcpp