// [method] Bottom-up dynamic programming

/**
 * Given an n-by-n matrix of integers ([-127, 127]), find a sub-matrix with
 * the maximum sum
 */

#include <iostream>
#include <limits>
#include <vector>

using namespace std;

using intmatrix = vector<vector<int>>;

int solve1d(const vector<int>& input) {
    int res = 0, sum = 0;
    for (int i = 0; i < input.size(); i++) {
        sum += input[i];
        res = max(res, sum);
        if (sum < 0) {
            sum = 0; // reset sum
        }
    }
    return res;
}

int solve2d(const intmatrix& input) {
    // Calculate cumulative matrix from original input
    intmatrix sum_mat = input;
    for (int r = 0; r < input.size(); r++) {
        for (int j = 0; j < input[0].size(); j++) {
            if (r > 0) {
                sum_mat[r][j] += sum_mat[r-1][j];
            }
            if (j > 0) {
                sum_mat[r][j] += sum_mat[r][j-1];
            }
            if (r > 0 && j > 0) {
                sum_mat[r][j] -= sum_mat[r-1][j-1];
            }
        }
    }

    // Similar to 1D, but in 2d
    int res = numeric_limits<int>::min();
    // i, j for upper left
    for (int i = 0; i < input.size(); i++) {
        for (int j = 0; j < input[0].size(); j++) {
            for (int k = i; k < input.size(); k++) {
                for (int l = j; l < input[0].size(); l++) {
                    int curr_sum = sum_mat[k][l];
                    if (i > 0) {
                        curr_sum -= sum_mat[i-1][l];
                    }
                    if (j > 0) {
                        curr_sum -= sum_mat[k][j-1];
                    }
                    if (i > 0 && j > 0) {
                        curr_sum += sum_mat[i-1][j-1];
                    }
                    res = max(res, curr_sum);
                }
            }
        }
    }

    return res;
}

int main() {
    // 1D
    vector<int> input1d1 = {4, -5, 4, -3, 4, 4, -4, 4, -5};
    cout << "max subarray sum is: " << solve1d(input1d1) << endl;

    // 2D
    vector<int> row1 = {0, -2, -7, 0};
    vector<int> row2 = {9, 2, -6, 2};
    vector<int> row3 = {-4, 1, -4, 1};
    vector<int> row4 = {-1, 8, 0, -2};

    vector<vector<int>> input2d1 = {row1, row2, row3, row4};
    cout << "max submatrix sum is: " << solve2d(input2d1) << endl;
    return 0;
}