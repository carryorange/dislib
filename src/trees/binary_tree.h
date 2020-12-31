#pragma once

#include <memory>

namespace carryorange {
namespace dslib {
namespace binary_tree {

/**
 *
 * Leaf tree vs node tree
 * [From Advanced Data Structure, Peter Brass, Chapter 2]
 * Leaf tree: a search tree model where internal nodes only store keys, and data
 * objects are only stored in leaf nodes Node tree: a search tree model where
 * internal nodes store both keys and data objects. For a binary tree whose
 * height is h, leaf tree can store 2^h data objects, whereas node tree can
 * store 2^(h+1)-1 data objects. However, leaf tree needs less comparisons
 * (since there's only a < check) when traversing the tree.
 *
 */

/**
 * @brief A base class for the tree node class hierarchy based on leaf tree
 * model as described above
 */
template <class KeyT>
struct NodeBase {
    using NodeBasePtr = std::shared_ptr<NodeBase>;
    NodeBasePtr left;
    NodeBasePtr right;
    KeyT key;
};

template <class KeyT, class NodeTypeT> 
struct Node : public NodeBase<KeyT> {
    bool isLeaf() const {  static_cast<const NodeTypeT*>(this)->isLeaf(); }

    KeyT key;
};

template <class KeyT>
class TreeNode : public Node<KeyT, TreeNode<KeyT>> {
  public:
    bool isLeaf() const { return false; }
};

template <class KeyT, class DataT>
class LeafNode : public Node<KeyT, LeafNode<KeyT, DataT>> {
  public:
    bool isLeaf() const { return true; }

  private:
    DataT m_data;
};

} // namespace binary_tree
} // namespace dslib
} // namespace carryorange