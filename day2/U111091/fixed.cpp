#include<bits/stdc++.h>
using namespace std;
typedef int i32;
typedef unsigned int u32;

#ifdef DEBUG
#define PRINT_VALUE(v){using namespace std;cout<<#v<<" :"<<v<<endl;}
#endif

#ifndef DEBUG
#define PRINT_VALUE(v)
#endif

const i32 MAX_N=5'0000;
u32 x[MAX_N],perfix[MAX_N+5],n,m,t,k;

template<typename T>
void set_mem(T *begin,u32 size,T value){
    for(u32 i=0;i<size;i++){
        begin[i]=0;
    }
}

u32 one_section(){
    u32 max_num=0;
    for(u32 i=1u;i<=n;i++){
        u32 j=1;
        while(i+j<=n&&x[i+j]-x[i]>m){
            j++;
        }
        j--;
        max_num = max(max_num,perfix[i+j]-perfix[i]);
    }
    PRINT_VALUE(max_num);
    return max_num;
}

int main(){
    cin>>t;
    PRINT_VALUE(t);
    for(u32 i=1;i<=t;i++){
        cin>>n>>k>>m;
        set_mem(perfix, n+1, 0u);
        for(u32 j=1;j<=n;j++){
            cin>>x[i];
        }
        string s;
        cin>>s;
        for(u32 j=0;j<s.size();j++){
            if (s[j]=='1') {
                perfix[j+2] = perfix[j+1] + ( x[j+2] - x[j+1] );
            }
        }
        u32 num = max(one_section(),(u32)0);
        cout<<num<<endl;
    }
}