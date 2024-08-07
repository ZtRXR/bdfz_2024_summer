#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int l2[n+1];
    l2[1]=0;
    for(int i=2;i<=n;i++){
        l2[i]=l2[i>>1]+1;
    }
    int k=l2[n]+1;
    int s[n+1][k+1];
    for(int i=1;i<=n;i++){
        cin>>s[i][0];
    }
    for(int j=1;j<=k;j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            s[i][j]=min(s[i][j-1],s[i+(1<<(j-1))][j-1]);
        }
    }
    int m;
    cin>>m;
    for(int i=1;i<=m;i++){
        int l,r;
        cin>>l>>r;
        int j=l2[r-l+1];
        cout<<min(s[l][j],s[r-(1<<j)+1][j])<<endl;
    }
}