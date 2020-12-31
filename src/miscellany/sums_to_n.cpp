// [method] Iterative complete search

/**
 * Give a list L containing 1 <= n <= 20 integers, is there a
 * subset of L that sums to another given integer X.
 */

// Analysis:
// Since the list size is limited (upper bound 20), we know the overall time complexity
// is at most 20 * 2 ^ 20 ~ 21M.
// So a brute force approach is feasible

#include <iostream>
#include <vector>

using namespace std;

void printResults(const vector<int> input, const int n, const int target)
{
    // use i as a bit mask. The outer loop iterates all possible subsets
    int i = 0;
    for (; i < (1 << n); i++) {
        int sum = 0;
        // Inner loop to calculate the sum of a given subset
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                sum += input[j];
            }
        }
        if (sum == target) { break; }
        
    }
}