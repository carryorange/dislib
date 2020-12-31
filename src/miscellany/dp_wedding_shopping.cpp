// [method] Top-down dynamic programming

/**
 * Given different options for each garment (shirt, belt, shoes etc.)
 * and a certain limited budget, the task is to buy one model of each garment,
 * And maximize the spending that's within the budget
 * Constraints: 1 <= budget <= 200,
 *              1 <= number of garments needed <= 20
 */

#include <algorithm> // max
#include <cassert>
#include <iostream>
#include <limits>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solver {
  public:
    Solver(const vector<vector<int>>& shopping_list, int budget)
        : m_shopping_list(shopping_list), m_budget(budget),
          m_cache(shopping_list.size()) {}

    // Solve the problem with top down dp
    int solve_td() { return max(m_budget - shop(m_budget, 0), 0); }

    // Solve the problem with bottom up dp
    int solve_bu() { return shop2(); }

  private:
    int shop(int budget, int g_idx) {
        string padding = string(g_idx * 2, ' ');
        cout << padding << "[debug] shop: budget=" << budget
             << ", g_idx=" << g_idx << '\n';

        assert(budget >= 0 && g_idx < m_shopping_list.size());

        // Check if we've seen this
        if (m_cache[g_idx].count(budget)) {
            cout << padding << "[debug] reading from cache: min_left=" << m_cache[g_idx][budget] << '\n';
            return m_cache[g_idx][budget];
        }

        int min_left = numeric_limits<int>::max();
        // Select one model and proceed
        for (int price : m_shopping_list[g_idx]) {
            if (budget < price) { continue; }
            int left = (g_idx+1 == m_shopping_list.size()) ? (budget - price) : shop(budget - price, g_idx+1);
            min_left = min(min_left, left);
        }

        m_cache[g_idx][budget] = min_left;
        cout << padding << "[debug] min_left=" << min_left << '\n';
        return min_left;
    }

    int shop2() {
        // dptable indicates whether a state is reachable or not
        vector<vector<bool>> dptable(m_shopping_list.size(), vector<bool>(m_budget+1, false));

        auto print_dptable = [&]() {
            cout << '\n';
            for (auto& row : dptable) {
                for (bool col : row) {
                    cout << col << ' ';
                }
                cout << '\n';
            }
            cout << endl;
        };

        // Set base cases
        int num_rows = m_shopping_list.size(), num_cols = m_shopping_list[0].size();
        for (int price : m_shopping_list[0]) {
            if (m_budget-price >= 0) {
                dptable[0][m_budget - price] = true;
            }
        }

        print_dptable();
        // We don't need dptable, we just need to store two rows to calculate the last row
        for (int g = 1; g < m_shopping_list.size(); g++) {
            for (int r = 0; r < dptable[0].size(); r++) {
                if (dptable[g-1][r]) {
                    for (int price : m_shopping_list[g]) {
                        if (r - price >= 0) {
                            dptable[g][r-price] = true;
                        }
                    }
                }
            }
            print_dptable();
        }

        for (int i = 0; i < num_cols; i++) {
            if (dptable[num_rows-1][i]) {
                return m_budget-i;
            }
        }

        return -1;
    }
    
    const vector<vector<int>>& m_shopping_list;
    const int m_budget;

    // State: min remaining money after selecting this garment
    vector<unordered_map<int, int>> m_cache;
};

int main() {
    vector<int> models_for_g1 = {6, 4, 8};
    vector<int> models_for_g2 = {5, 10};
    vector<int> models_for_g3 = {1, 5, 3, 5};
    vector<vector<int>> shopping_list = {models_for_g1, models_for_g2,
                                         models_for_g3};
    int budget = 20;

    Solver solver(shopping_list, budget);

    // cout << "max possible spending is: " << solver.solve_td() << endl;
    cout << "max possible spending is: " << solver.solve_bu() << endl;

    return 0;
}