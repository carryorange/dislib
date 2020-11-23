#pragma once

#include <cstdlib> // size_t
#include <type_utils.h>
#include <vector>

namespace carryorange {
namespace dslib {

/**
 * @brief a simple union-find disjoint set implementation.
 * Path compression and union-by-rank are implemented.
 */
class SimpleUFDS {
  public:
    SimpleUFDS(size_t max_size = 255);

    /**
     * @brief Union the sets node @param n1 and @param n2 are in.
     * @return the index of the set resulted from the union.
     */
    size_t makeUnion(size_t n1, size_t n2) noexcept(false);

    /**
     * @brief Get the index  of the set node @param n belongs to
     * The name will be an unsigned int
     */
    size_t getSetIndex(size_t n) noexcept(false);

    bool isSameSet(size_t n1, size_t n2) noexcept(false);

  private:
    std::vector<int32> m_nodes;
    std::vector<int32> m_ranks;
};

} // namespace dslib
} // namespace carryorange