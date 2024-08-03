#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 1e9+7;
const int MAX_N = 1e5+5;
int a[MAX_N];
int prefix_a[MAX_N];
int times;
int n;

signed main(){
    cin.sync_with_stdio(false);
    cin.tie(0);

    cin>>times;
    for (int t=1; t<=times; t++) {
        int cnt = 0;
        prefix_a[0] = 0;
        cin>>n;
        for (int i=1; i<=n; i++) {
            cin>>a[i];
            prefix_a[i] = (a[i]+prefix_a[i-1])%MOD;
        }
        /*
        cout<<"\nprefix_a:\n";
        for (int i=1; i<=n; i++) {
            cout<<prefix_a[i]<<" ";
        }
        cout<<"\n";
        */
        
        for (int l=1; l<=n; l++) {
            for (int r=l; r<=n; r++) {
                cnt=(
                        (
                            (prefix_a[r]-prefix_a[l-1])
                            /
                            (r-l+1)
                        )
                            +cnt
                    )%MOD;
            }
        }
        cout<<cnt<<"\n";
    }
}