#include "int_search_tree.h"

namespace carryorange {
namespace dslib {
namespace binary_tree {
bool BinaryTree::insert(int key)
{
    if (!m_root) {
        m_root = std::make_shared<InteriorNode>(key);
        m_root->m_right = std::make_shared<LeafNode>(key);
        return true;
    }

    NodeBase::NodeRef curr_node = m_root;
    NodeBase::NodeRef prev_node;
    while (curr_node && !curr_node->isLeaf()) {
        prev_node = curr_node;
        int curr_node_key = curr_node->m_key;
        if (key < curr_node_key) {
            curr_node = static_cast<InteriorNode*>(curr_node.get())->m_left;
        }
        else {
            curr_node = static_cast<InteriorNode*>(curr_node.get())->m_right;
        }
    }
    
    
}
} // namespace binary_tree
} // namespace dslib
} // namespace carryorange