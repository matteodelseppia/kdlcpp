#pragma once

#include <utility>

namespace kdlcpp {

/**
 * @brief A generic stream wrapper that abstracts away
 *        the interface of standard stream types (e.g., std::stringstream, std::fstream).
 * 
 * This class relies on the stream insertion operator (<<) 
 * to write data to the underlying stream object.
 * 
 * @tparam T The type of the stream being wrapped.
 */
template <typename stream_type>
class stream {
public:

  /**
   * @brief Constructs a stream wrapper by taking ownership
   *        of the provided stream object.
   * 
   * @param stream_instance The stream object to wrap.
   */
  explicit stream(stream_type&& stream_instance) noexcept
    : m_internal_stream(std::move(stream_instance)) {}

  /**
   * @brief Provides access to the underlying stream object.
   * 
   * @return A const reference to the wrapped stream.
   */
  [[nodiscard]] const stream_type& get() const noexcept {
    return m_internal_stream;
  }

  /**
   * @brief Writes a value to the stream using the << operator.
   * 
   * @tparam value_type The type of the value being written.
   * @param val The value to write.
   */
  template <typename value_type>
  void write(const value_type& val) {
    m_internal_stream << val;
  }

  /**
   * @brief Reads a value from the stream using the >> operator.
   * 
   * @tparam value_type The type of the value being read.
   * @param val The value to read.
   */
  template <typename value_type>
  void read(value_type& val) {
    m_internal_stream >> val;
  }

private:
  stream_type m_internal_stream;  ///< The wrapped stream object.
};

/**
 * @brief Overloads the << operator to allow writing to a kdlcpp::stream.
 * 
 * @tparam stream_type The type of the underlying stream.
 * @tparam value_type The type of the value to write.
 * @param stream_wrapper The stream wrapper instance.
 * @param val The value to write to the stream.
 * @return A reference to the stream wrapper.
 */
template <typename stream_type, typename value_type>
stream<stream_type>& operator<<(stream<stream_type>& stream_wrapper, const value_type& val) {
  stream_wrapper.write(val);
  return stream_wrapper;
}

/**
 * @brief Overloads the >> operator to allow reading from a kdlcpp::stream.
 * 
 * @tparam stream_type The type of the underlying stream.
 * @tparam value_type The type of the value to read.
 * @param stream_wrapper The stream wrapper instance.
 * @param val The value to read from the stream.
 * @return A reference to the stream wrapper.
 */
template <typename stream_type, typename value_type>
stream<stream_type>& operator>>(stream<stream_type>& stream_wrapper, value_type& val) {
  stream_wrapper.read(val);
  return stream_wrapper;
}

} // namespace kdlcpp