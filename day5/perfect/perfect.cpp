//暴力10/100points

#include<bits/stdc++.h>
using namespace std;

const int MAX_N=3e5+5;
int n;
int a[MAX_N];
int ans=INT_MIN;

int main(){
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int l=1;l<=n;l++){
        for(int r=l;r<=n;r++){
            int max_num=INT_MIN;
            int min_num=INT_MAX;
            for(int i=l;i<=r;i++){
                max_num=max(max_num,a[i]);
                min_num=min(min_num,a[i]);
            }
            ans=max(ans,max_num^min_num);
        }
    }
    cout<<ans<<endl;
}