#include <bits/stdc++.h>
#define int long long

const int MAX_N = 5*100'000;
const int MOD = 1'000'000'000 + 7;

int a[MAX_N],b[MAX_N];
int prefix_a[MAX_N],prefix_b[MAX_N];
int n;
int cnt=0;

signed main(){
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    prefix_a[0]=0;
    prefix_b[0]=0;
    std::cin>>n;
    for (int i=1;i<=n;i++) {
        std::cin>>a[i];
        prefix_a[i] = (a[i] + prefix_a[i-1])%MOD;
    }
    for(int i=1;i<=n;i++){
        std::cin>>b[i];
        prefix_b[i] = (b[i] + prefix_b[i-1])%MOD;
    }
    for (int l=1; l<=n; l++) {
        for (int r=l;r<=n;r++) {
            // int sum_a = ;
            // int sum_b = ;
            cnt = (cnt + (((prefix_a[r]-prefix_a[l-1]+MOD)%MOD)*((prefix_b[r]-prefix_b[l-1]+MOD)%MOD)))%MOD;
        }
    }
    std::cout<<cnt<<"\n";
}

// #include <iostream>
// #include <vector>
// using namespace std;

// const int MOD = 1e9 + 7;

// int main() {
//     int n;
//     cin >> n;
//     vector<int> a(n), b(n);

//     for (int i = 0; i < n; ++i) {
//         cin >> a[i];
//     }
//     for (int i = 0; i < n; ++i) {
//         cin >> b[i];
//     }

//     vector<long long> prefix_a(n + 1, 0), prefix_b(n + 1, 0);
//     for (int i = 1; i <= n; ++i) {
//         prefix_a[i] = (prefix_a[i - 1] + a[i - 1]) % MOD;
//         prefix_b[i] = (prefix_b[i - 1] + b[i - 1]) % MOD;
//     }

//     long long result = 0;

//     for (int l = 1; l <= n; ++l) {
//         for (int r = l; r <= n; ++ r) {
//             long long sum_a = (prefix_a[r] - prefix_a[l - 1] + MOD) % MOD;
//             long long sum_b = (prefix_b[r] - prefix_b[l - 1] + MOD) % MOD;
//             result = (result + sum_a * sum_b) % MOD;
//         }
//     }

//     cout << result << endl;
//     return 0;
// }
