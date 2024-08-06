//TODO fix bug input 3
//怀疑思路是否有问题，还是样例问题

#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#define PRINT_VALUE(v){cout<<#v<<" :"<<v<<endl;}
#endif
#ifndef DEBUG
#define PRINT_VALUE(v)
#endif

const int MAX_N=5*1e5+5;
int n,ans=0;
int num_times[MAX_N];
int arr[MAX_N];

void set_num_times_mem(){
    for(int i=0;i<MAX_N;i++){
        num_times[i]=0;
    }
}

int main(){
    cin>>n;
    set_num_times_mem();
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        num_times[arr[i]]++;
        PRINT_VALUE(i);
        PRINT_VALUE(arr[i])
        PRINT_VALUE(num_times[arr[i]]);
        if (i==1) {
            ans=max(num_times[arr[i]],ans);
        }else{
            if (i%2==0) {
                int mid1=arr[i/2];
                int mid2=arr[i/2+1];
                PRINT_VALUE(mid1);
                PRINT_VALUE(mid2);
                ans=max(max(num_times[mid1],num_times[mid2])
                            ,ans);
            }else {
                int mid=arr[i/2+1];
                PRINT_VALUE(mid);
                ans=max(num_times[mid],ans);
            }
        }
        PRINT_VALUE(ans);
        PRINT_VALUE("------\n");
    }
    cout<<ans<<endl;
}