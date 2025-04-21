#include "kdlcpp/value.hpp"

namespace kdlcpp {

value::type value::get_type() const noexcept {
  return m_type;
}

void value::update_type() {
  std::visit([this](const auto& content) {
    using T = std::decay_t<decltype(content)>;
    if constexpr (std::is_same_v<T, nulltype>) {
      m_type = type::null;
    } else if constexpr (std::is_same_v<T, boolean>) {
      m_type = type::boolean;
    } else if constexpr (std::is_same_v<T, integral>) {
      m_type = type::integral;
    } else if constexpr (std::is_same_v<T, decimal>) {
      m_type = type::decimal;
    } else if constexpr (std::is_same_v<T, string>) {
      m_type = type::string;
    }
  }, m_content);
}

} // namespace kdlcpp