//TODO FIXBUG 10/100points

#include<bits/stdc++.h>
using namespace std;

#define int long long

#ifdef DEBUG
#define PRINT_ARRAY(arr,size){cout<<#arr<<" [";for(int i=1;i<=(size);i++)cout<<arr[i]<<(i!=size?",":"]\n");}
#define PRINT_VALUE(v){cout<<#v<<" :"<<(v)<<endl;}
#define DEBUG_CODE(code){code}
#endif

#ifndef DEBUG
#define PRINT_ARRAY(arr,size)
#define PRINT_VALUE(v)
#define DEBUG_CODE(code)
#endif

const int MAX_NM=3*1e5+5;

struct point{
    int l,r,v;
}points[MAX_NM];
int n,m,w;
int diffv[MAX_NM];
int max_v=-1;
int diff_unkown_num[MAX_NM];

signed main(){
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>w;
    PRINT_VALUE(n);
    PRINT_VALUE(m);
    PRINT_VALUE(w);
    for (int i=1; i<=m; i++) {
        point &pi = points[i];
        cin>>points[i].l>>points[i].r>>points[i].v;
        if (pi.v==-1) {
            pi.v=0;
            // DEBUG_CODE(pi.v=w;)
            diff_unkown_num[pi.l]++;
            diff_unkown_num[pi.r+1]--;
        }
        PRINT_VALUE(i);
        PRINT_VALUE(pi.l);
        PRINT_VALUE(pi.r);
        PRINT_VALUE(pi.v);
        diffv[pi.l]+=pi.v;
        diffv[pi.r+1]-=pi.v;
    }
    PRINT_ARRAY(diff_unkown_num, n);
    PRINT_ARRAY(diffv, n);

    int *raw=diffv;
    int *raw_unkown_num=diff_unkown_num;
    for(int i=1;i<=n;i++){
        raw[i]=raw[i-1]+diffv[i];
        max_v=max(max_v,raw[i]);
        raw_unkown_num[i]=raw_unkown_num[i-1]+diff_unkown_num[i];
    }
    PRINT_ARRAY(raw_unkown_num, n)
    PRINT_ARRAY(raw, n);
    for (int i=1; i<=n; i++) {
        PRINT_VALUE(raw_unkown_num[i]*w);
        PRINT_VALUE(max_v-raw[i]);
        if(max_v-raw[i]<=(raw_unkown_num[i]*w)){
            cout<<1;
        }else {
            cout<<0;
        }
    }
    cout<<endl;
}