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
template <class KeyT> struct NodeBase {
  protected:
    NodeBase(const KeyT& key): m_key(key) {}
    KeyT m_key;
};

template <class KeyT, class NodeTypeT> struct Node : public NodeBase<KeyT> {
  public:
    Node(const KeyT& key): NodeBase<KeyT>(key) {}

    bool isLeaf() const { return static_cast<const NodeTypeT*>(this)->isLeaf(); }
};

template <class KeyT> class InteriorNode : public Node<KeyT, InteriorNode<KeyT>> {
  public:
    using InteriorRef = std::shared_ptr<InteriorNode<KeyT>>;
    InteriorNode(const KeyT& key):
      Node<KeyT, InteriorNode<KeyT>>(key) {}
    
    bool isLeaf() const { return false; }

  private:
    InteriorRef m_left;
    InteriorRef m_right;
};

template <class KeyT, class DataT>
class LeafNode : public Node<KeyT, LeafNode<KeyT, DataT>> {
  public:
    LeafNode(const KeyT& key, const DataT& data): Node<KeyT, InteriorNode<KeyT>>(key), m_data(data) {}
    bool isLeaf() const { return true; }

  private:
    DataT m_data;
};

template <class KeyT, class DataT = KeyT> class BinaryTree {
  public:
    using LeafRef = std::shared_ptr<LeafNode<KeyT, DataT>>;
    using ValueType = std::pair<KeyT, DataT>;

    BinaryTree() {}

    // A new key is always inserted at the leaf
    bool insert(const ValueType& val) {
        if (!m_root) {
            m_root = std::make_shared<InteriorNode<KeyT>>(val.first);
        }
        return false; // TODO
    }

  private:
    using InteriorRef = InteriorNode<KeyT>::InteriorRef;
    InteriorRef m_root;
};

} // namespace binary_tree
} // namespace dslib
} // namespace carryorange