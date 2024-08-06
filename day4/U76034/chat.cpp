#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#define MOD 1000000007

using namespace std;

#ifdef DEBUG
#define PRINT_VALUE(v){cout<<#v<<" :"<<v<<endl;}
#define PRINT_ARRAY(arr,size){cout<<#arr<<" [";for(int i=1;i<=size;i++){cout<<arr[i]<<(i!=size?",":"]\n");}}
#endif

#ifndef DEBUG
#define PRINT_VALUE(v)
#define PRINT_ARRAY(arr,size)
#endif

typedef long long ll;

ll power(ll a, ll b, ll mod) {
    ll res = 1;
    while (b > 0) {
        if (b % 2 == 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return res;
}

map<ll, ll> prime_factorization(ll x) {
    map<ll, ll> factors;
    for (ll i = 2; i * i <= x; ++i) {
        while (x % i == 0) {
            factors[i]++;
            x /= i;
        }
    }
    if (x > 1) {
        factors[x]++;
    }
    return factors;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    vector<pair<ll, ll>> queries(q);

    for (int i = 0; i < q; ++i) {
        cin >> queries[i].first >> queries[i].second;
    }

    const int MAXN = 1e6 + 5;
    vector<ll> fact(2 * MAXN), invFact(2 * MAXN);

    fact[0] = 1;
    for (int i = 1; i < 2 * MAXN; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    invFact[2 * MAXN - 1] = power(fact[2 * MAXN - 1], MOD - 2, MOD);
    for (int i = 2 * MAXN - 2; i >= 0; --i) {
        invFact[i] = invFact[i + 1] * (i + 1) % MOD;
    }

    auto binomial = [&](ll n, ll k) {
        if (n < k) return 0LL;
        return fact[n] * invFact[k] % MOD * invFact[n - k] % MOD;
    };

    for (auto [x, n] : queries) {
        if (n == 1) {
            cout << (x == 1 ? 1 : 2) << '\n';
            continue;
        }
        
        map<ll, ll> factors = prime_factorization(x);
        ll result = 1;
        
        for (auto [p, e] : factors) {
            result = result * binomial(2 * n + e - 1, e) % MOD;
        }
        
        cout << result << '\n';
    }

    return 0;
}
