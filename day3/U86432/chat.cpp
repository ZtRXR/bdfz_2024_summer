#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, m, r, k;
    cin >> n >> m >> r >> k;
    
    vector<vector<int>> fish_count(n + 1, vector<int>(m + 1, 0));
    
    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> x >> y;
        fish_count[x][y]++;
    }
    
    vector<vector<int>> prefix(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            prefix[i][j] = fish_count[i][j] 
                         + (i > 1 ? prefix[i - 1][j] : 0)
                         + (j > 1 ? prefix[i][j - 1] : 0)
                         - (i > 1 && j > 1 ? prefix[i - 1][j - 1] : 0);
        }
    }
    
    unordered_map<int, long long> result;
    
    for (int i = 1; i <= n - r + 1; ++i) {
        for (int j = 1; j <= m - r + 1; ++j) {
            int x1 = i, y1 = j;
            int x2 = i + r - 1, y2 = j + r - 1;
            int fish_in_net = prefix[x2][y2]
                            - (x1 > 1 ? prefix[x1 - 1][y2] : 0)
                            - (y1 > 1 ? prefix[x2][y1 - 1] : 0)
                            + (x1 > 1 && y1 > 1 ? prefix[x1 - 1][y1 - 1] : 0);
            result[fish_in_net]++;
        }
    }
    
    // Output results
    for (int i = 0; i <= k; ++i) {
        cout << result[i] << endl;
    }

    return 0;
}
