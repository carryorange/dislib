// [method] Recursive complete search (with pruning)

/**
 * Eight queens problem, with one additional constraint:
 * One queen is already given (position q_x, q_y)
 */

// Idea: use row[i] to represent the column the queen is put on row i
#include <cstdlib> // size_t
#include <iostream>

using namespace std;

const size_t num_rows = 8;
// Given queens position
int r_must = 1, c_must = 5;

void printBoard(int row[num_rows]) {
    cout << "  0 1 2 3 4 5 6 7\n";
    for (int i = 0; i < num_rows; i++) {
        cout << i;
        for (int j = 0; j < num_rows; j++) {
            if (j == row[i]) {
                cout << " x";
            }
            else {
                cout << "  ";
            }
        }
        cout << '\n';
    }
    cout << endl;
}

void backtrack(const int r, int row[num_rows]) {
    if (r == num_rows) {
        // valid board. Check input
        if (row[r_must] == c_must) {
            printBoard(row);
        }
    }

    for (int c = 0; c < num_rows; c++) {
        // constraints check
        bool valid = true;
        for (int prev_r = r-1; prev_r >= 0; prev_r--) {
            int prev_c = row[prev_r];

            // Same column
            if (prev_c == c /*same column*/ || 
                abs(r - prev_r) == abs(c - prev_c) /* diagoncal */) {
                valid = false;
                break;
            }
        }

        if (valid) {
            row[r] = c;
            backtrack(r+1, row);
            row[r] = 0;
        }
    }
}

int main() {
    int board[8] = {0};
    backtrack(0, board);
    return 0;
}