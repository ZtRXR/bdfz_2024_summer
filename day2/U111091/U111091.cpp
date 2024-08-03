#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 5'0000+5;
int times;
int n,k,m;
int x[MAX_N];
int l[MAX_N];


int main(){
    cin.sync_with_stdio(false);
    cin.tie(0);

    cin>>times;
    for(int t=1;t<=times;t++){
        cin>>n>>k>>m;
        for (int i=1; i<=n; i++) {
            cin>>x[i];
        }
        string s;
        cin>>s;
        assert(s.size()==n-1);
        for(int i=0;i<=s.size();i++){
            if (s[i]=='0') {
                l[i+1]=0;
            }else {
                l[i+1]=1;
            }
        }
        
    }

}