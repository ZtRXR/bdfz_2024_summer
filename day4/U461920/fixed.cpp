//fixed 暴力 11 points sub task 1

#include<bits/stdc++.h>
using namespace std;

// #define DEBUG

#ifdef DEBUG
#define PRINT_ARRAY(a,size){cout<<#a<<" [";for(int i=1;i<=(size);i++){cout<<a[i]<<(i!=(size)?",":"]\n");}}
#define PRINT_VALUE(v){cout<<#v<<" :"<<v<<endl;}
#define PRINT_DEBUG(v){cout<<v<<endl;}
#define DEBUG_CODE(v){v}
#endif

#ifndef DEBUG
#define PRINT_ARRAY(a,size)
#define PRINT_VALUE(v)
#define PRINT_DEBUG(v)
#define DEBUG_CODE(v)
#endif

const int MAX_N=5*1e5+5;
int n;
int a[MAX_N];
int b[MAX_N];

int compute_max_num(int b[],int size){
    sort(b,b+size);
    PRINT_ARRAY(b, size);
    if (size==1) {
        return 1;
    }else if(size%2==0){
        int mid1=b[size/2],mid1_num=0;
        int mid2=b[size/2+1],mid2_num=0;

        for (int i=1; i<=size; i++) {
            if (mid1==b[i]) {
                mid1_num++;
            }else if(mid2==b[i]){
                mid2_num++;
            }
        }
        return max(mid1_num,mid2_num);
    }else{
        int mid=b[size/2+1];
        int mid_num=0;
        for(int i=1;i<=size;i++){
            if (b[i]==mid) {
                mid_num++;
            }
        }
        return mid_num;
    }
}

int check_every_sub(int a[],int size){
    int ans=0;
    for(int i=1;i<=size;i++){
        for(int j=i;j<=size;j++){
            for (int k=i; k<=j; k++) {
                b[k-i+1]=a[k];
            }
            ans=max(ans,compute_max_num(b, j-i+1));
        }
    }
    return ans;
}

int main(){
    cin.sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    cout<<check_every_sub(a, n)<<endl;
}