// A quick implementation of search tree which uses integers as keys
// and does not store any data.
// left subtree: <
// right subtree: >=
#pragma once

#include <memory>
#include <utility>
namespace carryorange {
namespace dslib {
namespace binary_tree {

struct NodeBase
{
    using NodeRef = std::shared_ptr<NodeBase>;
    NodeBase(int key): m_key(key) {}
    virtual bool isLeaf() const = 0;

    int m_key;
};

struct InteriorNode: public NodeBase
{
    InteriorNode(int key): NodeBase(key) {}

    NodeRef m_left;
    NodeRef m_right;

    bool isLeaf() const { return false; }
};

struct LeafNode: public NodeBase
{
    LeafNode(int key): NodeBase(key) {}
    bool isLeaf() const { return true; }
};

struct BinaryTree
{
    // if key does not exist, insert and return true;
    // else return false and does nothing // no override
    bool insert(int key);
    std::shared_ptr<InteriorNode> m_root;
};

} // namespace binary_tree
} // namespace dslib
} // namespace carryorange