// [method] DP

/**
 * Question: 
 * given coin denominations denom[0..n-1], and an expected value.
 * What's the minimum number of coins needed to get expected value
 * (assume unlimited suppy of each denomination)
 * 
 * Variant
 * What is the total possible ways to get the expected value
 */

#include <algorithm>
#include "typedefs.h"

using namespace std;

class MinCountSolver
{
public:
    MinCountSolver(const vi& coins, const int target):
        m_coins(coins), m_target(target) {}

    // Bottom up DP
    int solve() {
        sort(m_coins.begin(), m_coins.end());
        vi min_coin_cache(m_target+1, 0);

        for (int i = 1; i < min_coin_cache.size(); i++) {
            int curr_count = numeric_limits<int>::max();
            for (int coin_val : m_coins) {
                if (coin_val > i) { break; } // m_coins needs to be sorted
                curr_count = min(curr_count, min_coin_cache[i - coin_val]);
            }
            min_coin_cache[i] = curr_count + 1;
        }

        return min_coin_cache[m_target];
    }

private:
    vi m_coins;
    const int m_target;
};

class TotalWaysSolver
{
public:
    TotalWaysSolver(const vi& coins, const int target):
        m_coins(coins), m_target(target) {}

    // Top down DP
    int solve() {
        return solve_impl(0, m_target);
    }

private:
    int solve_impl(int coin_idx, int target) {
        if (coin_idx == m_coins.size()) { return 0; }
        if (target < 0) { return 0; }
        if (target == 0) { return 1; }

        return solve_impl(coin_idx+1, target) + solve_impl(coin_idx, target-m_coins[coin_idx]);
    }

    vi m_coins;
    const int m_target;
};

int main() {
    vi coins = {1, 3, 4, 5};
    int expected = 7;

    MinCountSolver solver1(coins, expected);
    cout << "Min number of coins = " << solver1.solve() << endl;

    vi coins2 = {1, 5};
    int expected2 = 10;

    TotalWaysSolver solver2(coins2, expected2);
    cout << "Total number of ways = " << solver2.solve() << endl;

    TotalWaysSolver solver2_2(coins, expected);
    cout << "Total number of ways = " << solver2_2.solve() << endl;
    return 0;
}