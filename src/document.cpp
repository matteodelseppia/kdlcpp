#include "kdlcpp/document.hpp"

namespace kdlcpp {

const node& document::root() const noexcept {
  return m_root;
}

string_type document::name() const noexcept {
  return m_document_name;
}

node& document::root() noexcept {
  return m_root;
}

void document::set_name(const string_type& name) noexcept {
  m_document_name = name;
}

void document::set_root(node&& root) noexcept {
  m_root = std::move(root);
}

void document::write_to_file(const string_type& file_path) {
}

} // namespace kdlcpp