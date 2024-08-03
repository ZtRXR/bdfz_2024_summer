#include <iostream>
#include <vector>
#include <algorithm>

const int MOD = 1e4 + 7;
using namespace std;

int count_black_rectangles(const vector<vector<int>>& grid, int n) {
    vector<vector<int>> heights(n, vector<int>(n, 0));
    int total_rectangles = 0;

    
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < n; ++i) {
            if (grid[i][j]) {
                heights[i][j] = (i > 0 ? heights[i - 1][j] + 1 : 1);
            }
        }
    }


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j]) {
                int min_height = heights[i][j];
                for (int k = j; k >= 0 && grid[i][k]; --k) {
                    min_height = min(min_height, heights[i][k]);
                    if (min_height >= 2) {
                        total_rectangles += min_height - 1;
                    }
                }
            }
        }
    }

    return total_rectangles;
}

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> grid(n, vector<int>(n, 0));
    
    for (int i = 0; i < n; ++i) {
        string row;
        cin >> row;
        for (int j = 0; j < n; ++j) {
            grid[i][j] = row[j] - '0';
        }
    }

    int total_rectangles = count_black_rectangles(grid, n);


    long long result = (1LL * total_rectangles * (total_rectangles - 1) / 2) % MOD;

    cout << result << endl;
    
    return 0;
}
