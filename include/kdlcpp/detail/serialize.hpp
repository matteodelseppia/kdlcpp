#pragma once

#include "kdlcpp/stream.hpp"
#include "kdlcpp/value.hpp"
#include "kdlcpp/detail/tokens.hpp"
#include "kdlcpp/properties.hpp"
#include "kdlcpp/arguments.hpp"
#include "kdlcpp/node.hpp"
#include "kdlcpp/document.hpp"

namespace kdlcpp::detail::serialize {

/**
 * @brief Serializes a `kdlcpp::value` instance into a stream.
 * 
 * Supported value types:
 * - null      → `"null"`
 * - boolean   → `"true"` or `"false"`
 * - integral  → `123`
 * - decimal   → `3.14`
 * - string    → `"hello"`
 *
 * @tparam stream_type The underlying stream type.
 * @param out_stream The destination stream.
 * @param val The value to serialize.
 */
template <typename stream_type>
void serialize_value(stream<stream_type>& out_stream, const value& val) {
  switch (val.get_type()) {
    case value::type::null:
      out_stream << tokens::$null;
      break;
    case value::type::boolean: {
      auto content = val.get<value::boolean>();
      if (content) {
        out_stream << (*content ? tokens::$true : tokens::$false);
      }
      break;
    }
    case value::type::integral: {
      auto content = val.get<value::integral>();
      if (content) {
        out_stream << *content;
      }
      break;
    }
    case value::type::decimal: {
      auto content = val.get<value::decimal>();
      if (content) {
        out_stream << *content;
      }
      break;
    }
    case value::type::string: {
      auto content = val.get<value::string>();
      if (content) {
        out_stream << tokens::$quote << *content << tokens::$quote;
      }
      break;
    }
  }
}

/**
 * @brief Serializes a key-value property.
 * 
 * Format: `"key"=value`
 * 
 * @tparam stream_type The underlying stream type.
 * @param out_stream The destination stream.
 * @param key The property key.
 * @param val The property value.
 */
template <typename stream_type>
void serialize_property(
  stream<stream_type>& out_stream, const string_type& key, const value& val) {
  out_stream << tokens::$quote << key << tokens::$quote;
  out_stream << tokens::$equal;
  serialize_value(out_stream, val);
}

/**
 * @brief Serializes a list of properties.
 * 
 * @tparam stream_type The underlying stream type.
 * @param out_stream The destination stream.
 * @param props The collection of properties.
 */
template <typename stream_type>
void serialize_properties(
  stream<stream_type>& out_stream, const properties& props) {
  for (const auto& [key, val] : props) {
    serialize_property(out_stream, key, val);
    out_stream << tokens::$space;
  }
}

/**
 * @brief Serializes a list of arguments.
 * 
 * @tparam stream_type The underlying stream type.
 * @param out_stream The destination stream.
 * @param args The list of arguments.
 */
template <typename stream_type>
void serialize_arguments(
  stream<stream_type>& out_stream, const arguments& args) {
  for (const auto& arg : args) {
    serialize_value(out_stream, arg);
    out_stream << tokens::$space;
  }
}

/**
 * @brief Serializes a KDL node and its children recursively.
 * 
 * Format:
 * ```
 * node-name arg1 arg2 key="value" {
 *   child-node ...
 * }
 * ```
 * 
 * @tparam stream_type The underlying stream type.
 * @param out_stream The destination stream.
 * @param node_ The node to serialize.
 */
template <typename stream_type>
void serialize_node(
  stream<stream_type>& out_stream, const node& node_) {
  out_stream << node_.get_name() << tokens::$space;
  serialize_arguments(out_stream, node_.get_arguments());
  serialize_properties(out_stream, node_.get_properties());
  out_stream << tokens::$lbrace << tokens::$newln;
  for (const auto& child : node_.get_children()) {
    serialize_node(out_stream, child);
  }
  out_stream << tokens::$newln << tokens::$rbrace << tokens::$newln;
}

/**
 * @brief Serializes a `kdlcpp::document` into a stream.
 * 
 * This function outputs the document name as a comment header,
 * followed by serialization of all root-level child nodes.
 * 
 * Format:
 * ```
 * // document-name
 * <node serialization...>
 * ```
 * 
 * @tparam stream_type The type of the underlying stream.
 * @param out_stream The output stream to write to.
 * @param doc The document to serialize.
 */
template <typename stream_type>
void serialize_document(
  stream<stream_type>& out_stream, const document& doc) {
  out_stream << tokens::$slash << tokens::$slash << tokens::$space;
  out_stream << doc.name() << tokens::$newln;
  for (const auto& node_: doc.root().get_children()) {
    serialize_node(out_stream, node_);
  }
}


} // namespace kdlcpp::detail::serialize
  