//NOT DONE 
//TODO BUGFIX
#include<bits/stdc++.h>
using namespace std;

#ifdef OIDEBUG
#define PRINT_ARRAY(v,size){cout<<#v<<" [";for(int i=1;i<=size;i++){cout<<v[i]<<(i!=(size)?",":"]\n");}}
#define PRINT_VALUE(v){cout<<#v<<" :"<<(v)<<endl;}
#define DEBUG_CODE(code){code}
#endif

#ifndef OIDEBUG
#define PRINT_ARRAY(v,size)
#define PRINT_VALUE(v)
#define DEBUG_CODE(code)
#endif

const int MAX_N=1e3+5;
constexpr const int MAX_K=303;
int k,log_2[MAX_N],n,a[MAX_N],s[MAX_N][MAX_K],m;

int main(){
    cin>>n>>m;
    log_2[1]=0;
    for(int i=2;i<=n;i++){
        log_2[i]=log_2[i/2]+1;
    }
    k=log_2[n]+1;
    PRINT_VALUE(log_2[3])
    PRINT_ARRAY(log_2, n)
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    PRINT_ARRAY(a, n);
    for(int i=1;i<=n;i++){
        s[i][0]=a[i];
    }
    PRINT_VALUE(k);
    for(int j=1;j<=k;j++){
        PRINT_VALUE(1<<j);
        for(int i=1;i+(1<<j)-1<=n;i++){
            PRINT_VALUE(i);
            PRINT_VALUE(j);
            PRINT_VALUE(i+(1<<j))
            s[i][j]=min(s[i][j-1],s[i+(j>>1)][j-1]);
            PRINT_VALUE(s[i][j]);
        }
    }

    for(int i=1;i<=m;i++){
        int r,l;
        cin>>l>>r;
        PRINT_VALUE(l);
        PRINT_VALUE(r);
        int j=log_2[r-l+1];
        PRINT_VALUE(j);
        PRINT_VALUE(r-l+1);
        PRINT_VALUE(s[l][j]);
        PRINT_VALUE(s[r-(1<<j)+1][j]);
        PRINT_VALUE(r-(1<<j)+1);
        PRINT_VALUE(1<<j);
        cout<<min(s[l][j],s[r-(1<<j)+1][j])<<endl;
    }
}