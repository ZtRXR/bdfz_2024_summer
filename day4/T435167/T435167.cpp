//20% points

#include<bits/stdc++.h>
using namespace std;
#define int long long

const int MAX_N = 1e3+5;
int t,n;
int a[MAX_N],b[MAX_N];

bool checkAllEleGoUp(){
    for(int i=2;i<=n;i++){
        if (a[i]<a[i-1]) {
            return false;
        }
    }
    return true;
}

signed main(){
    cin>>t;
    for(int i=1;i<=t;i++){
        bool isAllBZero=true;
        cin>>n;
        for(int j=1;j<=n;j++){
            cin>>a[j];
        }
        for(int j=1;j<=n;j++){
            cin>>b[j];
            if(b[j]!=0){
                isAllBZero=false;
            }
        }
        bool isAllEleGoUp=checkAllEleGoUp();
        if (isAllEleGoUp) {
            cout<<0<<endl;
            continue;
        }
        if (isAllBZero) {
            cout<<-1<<endl;
            continue;
        }
        cout<<0<<endl;
    }
}