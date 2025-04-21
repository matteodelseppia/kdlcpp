#pragma once

#include "kdlcpp/node.hpp"

namespace kdlcpp {

/**
 * A document represents an entire KDL document. It has:
 * - A root node, which contains all the document data
 * - An optional name
 *
 * The document acts as the entry point for reading or writing KDL structures.
 */
class document {
public:

  /**
   * Gets the root node of the document.
   * @return A const reference to the root kdlcpp::node.
   */
  [[nodiscard]] const node& root() const noexcept;

  /**
   * Gets the name of the document.
   * @return A string_type representing the document name.
   */
  [[nodiscard]] string_type name() const noexcept;

  /**
   * Gets a modifiable reference to the root node of the document.
   * @return A reference to the root kdlcpp::node.
   */
  [[nodiscard]] node& root() noexcept;

  /**
   * Sets the name of the document.
   * @param name The new name to assign.
   */
  void set_name(const string_type& name) noexcept;

  /**
   * Sets the root node of the document by moving in a new node.
   * @param root The new root node to assign.
   */
  void set_root(node&& root) noexcept;

  /**
   * Serializes and writes the KDL document to a file.
   * @param aPath The path where the document should be written.
   */
  void write_to_file(const string_type& filepath);

private:
  node m_root;
  string_type m_document_name;
};

} // namespace kdlcpp
