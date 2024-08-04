#include<bits/stdc++.h>
using namespace std;

#define GET_ARRAY_LEN(a)(sizeof(a)/sizeof(a[0]))
#define SET_ARRAY(a){for(size_t i=0;i<GET_ARRAY_LEN(a);i++)a[i]=0;}
#define PRINT_VALUE(v){cout<<#v<<" :"<<v<<endl;}
#define PRINT_ARRAY(a,len){cout<<#a<<" [";for(unsigned int i=0;i<len;i++){cout<<a[i]<<(i!=len-1?",":"]\n");}}

unsigned int n;
unsigned cnt=0;
unsigned arrange_num=0;

void sort_fix(int arr[]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                cnt++;
            }
        }
    }
}

void build_array(unsigned int now,unsigned int end,int arr[],bool visited[]){
    if(now==end){
        // PRINT_VALUE(cnt);
        // PRINT_ARRAY(arr, n);
        sort_fix(arr);
        // PRINT_VALUE(cnt);
        arrange_num++;
        return;
    }
    for (unsigned int i=1; i<=n; i++) {
        if (visited[i]==true) {
            continue;
        }
        visited[i]=true;
        arr[now]=i;
        // PRINT_ARRAY(visited, n+1);
        build_array(now+1, end, arr, visited);
        visited[i]=false;
    }   
}

int main(){
    cin>>n;
    bool visited[n+1];
    // SET_ARRAY(visited);
    int arr[n+1];
    build_array(0, n,arr,visited);
    // PRINT_VALUE(cnt);
    // PRINT_VALUE(arrange_num);
    cout<<(cnt/arrange_num)%(int)(1e9+7)<<endl;
}