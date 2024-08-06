#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;

#ifdef DEBUG
#define PRINT_VALUE(v){cout<<#v<<" :"<<v<<endl;}
#define PRINT_ARRAY(arr,size){cout<<#arr<<" [";for(int i=1;i<=size;i++){cout<<arr[i]<<(i!=size?",":"]\n");}}
#define DEBUG_PRINT(c){cout<<c<<endl;}
#endif

#ifndef DEBUG
#define PRINT_VALUE(v)
#define PRINT_ARRAY(arr,size)
#define DEBUG_PRINT(c)
#endif

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> lim(n);
    for (int i = 0; i < n; ++i) {
        cin >> lim[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    dp[0][0] = 1;

    vector<int> positions;
    for (int i = 1; i <= n; ++i) {
        if (lim[i - 1] == 0) {
            positions.push_back(i);
        }
    }
    
    int total_permutations = 1;
    for (int i = 1; i <= positions.size(); ++i) {
        total_permutations = (total_permutations * i) % MOD;
    }

    for (int i = 1; i <= n; ++i) {
        if (lim[i - 1] != 0) {
            for (int j = 0; j <= m; ++j) {
                dp[i][j] = dp[i - 1][j];
            }
        } else {
            for (int j = 0; j <= m; ++j) {
                for (int k = 0; k < i; ++k) {
                    if (j - k >= 0) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % MOD;
                    }
                }
            }
        }
    }

    int result = 0;
    for (int j = 0; j <= m; ++j) {
        result = (result + dp[n][j]) % MOD;
    }
    
    result = (result * total_permutations) % MOD;

    cout << result << endl;

    return 0;
}
