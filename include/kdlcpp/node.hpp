#pragma once

#include "kdlcpp/arguments.hpp"
#include "kdlcpp/properties.hpp"

#include <vector>

namespace kdlcpp {

class node;
using node_list = std::vector<node>;

/**
 * A node is the core element in KDL. Each node has:
 * - A name (string_type)
 * - An ordered list of arguments (kdlcpp::arguments)
 * - A set of named properties (kdlcpp::properties)
 * - A list of child nodes (other kdlcpp::node instances)
 *
 * Nodes form a tree structure where each node can have zero or more children.
 */
class node {
public:
  /**
   * A node must at least have a name.
   */
  node(const string_type& name) : m_name(name) {}

  /**
   * Gets the name of the node.
   * @return A string representing the node's name.
   */
  [[nodiscard]] string_type get_name() const noexcept;

  /**
   * Gets the list of arguments passed to this node.
   * @return A const reference to the kdlcpp::Arguments object.
   */
  [[nodiscard]] const arguments& get_arguments() const noexcept;

  /**
   * Gets the map of properties for this node.
   * @return A const reference to the kdlcpp::Properties object.
   */
  [[nodiscard]] const properties& get_properties() const noexcept;

  /**
   * Gets the child nodes of this node.
   * @return A const reference to the list of child nodes.
   */
  [[nodiscard]] const node_list& get_children() const noexcept;

  /**
   * Gets a modifiable reference to the node's arguments.
   * @return A reference to the kdlcpp::Arguments object.
   */
  [[nodiscard]] arguments& get_arguments() noexcept;

  /**
   * Gets a modifiable reference to the node's properties.
   * @return A reference to the kdlcpp::Properties object.
   */
  [[nodiscard]] properties& get_properties() noexcept;

  /**
   * Gets a modifiable reference to the list of child nodes.
   * @return A reference to the list of child nodes.
   */
  [[nodiscard]] node_list& get_children() noexcept;

private:
  string_type m_name;
  arguments m_arguments;
  properties m_properties;
  node_list m_children;
};

} // namespace kdlcpp