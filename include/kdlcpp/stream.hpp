#pragma once

namespace kdlcpp {

template <typename T>
class stream {
public:
  stream(T& stream_impl) : m_stream_impl(stream_impl) {}

  template <typename U>
  void write(const U& val) {
    m_stream_impl << val;
  }

private:
  T& m_stream_impl;
};

template <typename T, typename stream_t>
stream<stream_t>& operator<<(stream<stream_t>& str, const T& val) {
  str.write(val);
  return str;
}

}