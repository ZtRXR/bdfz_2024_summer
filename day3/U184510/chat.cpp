#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int mod_inv(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;
    if (m == 1) return 0;
    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0) x1 += m0;
    return x1;
}

int main() {
    int n;
    cin >> n;

    vector<long long> dp(n + 1, 0);
    for (int i = 2; i <= n; ++i) {
        dp[i] = (dp[i - 1] + (i * (i - 1) / 2) % MOD * mod_inv(i, MOD)) % MOD;
    }

    cout << dp[n] << endl;
    return 0;
}