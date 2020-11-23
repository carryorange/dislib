#include "union_set.h"

namespace carryorange {
namespace dslib {
SimpleUFDS::SimpleUFDS(size_t max_size) {
    m_nodes.resize(max_size, -1);
    m_ranks.resize(max_size, 0);
}

size_t SimpleUFDS::makeUnion(size_t n1, size_t n2) {
    size_t root1 = getSetIndex(n1);
    size_t root2 = getSetIndex(n2);

    size_t new_root = root1;
    if (root1 != root2) {
        // Union-by-rank. Use the root with larger rank as root
        if (m_ranks[root1] < m_ranks[root2]) {
            new_root = root2;
            m_nodes[root1] = new_root;
        }
        else if (m_ranks[root1] > m_ranks[root2]) {
            new_root = root1;
            m_nodes[root2] = root1;
        }
        else {
            // Use root1 as new_root to break the tie
            new_root = root1;
            m_nodes[root2] = root1;
            m_ranks[root1]++;
        }
    }
    return new_root;
}

size_t SimpleUFDS::getSetIndex(size_t n) {
    if (m_nodes.at(n) != n) {
        size_t root = getSetIndex(m_nodes[n]); 
        m_nodes[n] = root; // path compression
    }
    return m_nodes[n];
}

bool SimpleUFDS::isSameSet(size_t n1, size_t n2) {
    return getSetIndex(n1) == getSetIndex(n2);
}

} // namespace dslib
} // namespace carryorange