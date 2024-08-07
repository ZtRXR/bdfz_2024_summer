#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#define PRINT_VALUE(v){cout<<#v<<" :"<<(v)<<endl;}
#endif

#ifndef DEBUG
#define PRINT_VALUE(v)
#endif

#define ll long long
#define int long long

ll _ksm(ll a, ll b,ll M){
    ll res = 1;
    while(b) {
        if(b & 1)                    
            res = res * a % M;       
        a = a * a % M;               
        b >>= 1;                     
    }
    return res;
}

ll ksm(ll a,ll b,ll M){
    return a * _ksm(b, M - 2,M) % M;
}

int n,k,m,times=1,b;

signed main(){
    cin>>n>>k>>m;
    b=k;
    /*
    x=k+x/b
    bx=k*b+x
    (b-1)x=k*b
    x=(k*b)/(b-1)
    */
    PRINT_VALUE(b);
    PRINT_VALUE(n);
    PRINT_VALUE(b<n);
    while(b<n){
        PRINT_VALUE(b<n);
        PRINT_VALUE(b*k);
        b=b*k;
        times++;
        PRINT_VALUE(times);
    }
    PRINT_VALUE(k);
    PRINT_VALUE(b);
    PRINT_VALUE(ksm(k*b,b-1,m));
    cout<<ksm(k*b,b-1,m)<<endl;
}