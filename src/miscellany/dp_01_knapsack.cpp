// [method] Top-down DP

#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

using vi = vector<int>;
using vvi = vector<vector<int>>;

class Solver {
  public:
    Solver(const vi& values, const vi& weights, const int max_weight)
        : m_values(values), m_weights(weights), m_maxweight(max_weight) {}

    int solve() {
        return solve_impl(0, m_maxweight);
    }

  private:
    int solve_impl(int id, int remaining_w) {
        if (id == m_values.size()) {
            return 0; // no more items
        }

        if (remaining_w <= 0) {
            return 0;
        }

        if (remaining_w < m_weights[id]) {
            // cannot put current item. Go for the next
            return solve_impl(id+1, remaining_w);
        }
        else {
            return max(solve_impl(id+1, remaining_w), m_values[id] + solve_impl(id+1, remaining_w - m_weights[id]));
        }

        assert(false); // shouldn't get here
    }
    const vi& m_values;
    const vi& m_weights;
    const int m_maxweight;
};

int main() {
    vector<int> vals = {100, 70, 50, 10};
    vector<int> weights = {10, 4, 6, 12};
    int weight_limit = 12;

    Solver solver(vals, weights, weight_limit);
    cout << "max possible value is: " << solver.solve() << endl;
    return 0;
}