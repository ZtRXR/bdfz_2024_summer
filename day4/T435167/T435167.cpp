//20% points

#include<bits/stdc++.h>
using namespace std;
#define int long long

#ifdef DEBUG
#define PRINT_VALUE(v){cout<<#v<<" :"<<v<<endl;}
#define PRINT_ARRAY(arr,size){cout<<#arr<<" [";for(int i=1;i<=size;i++){cout<<arr[i]<<(i!=size?",":"]\n");}}
#define DEBUG_PRINT(c){cout<<c<<endl;}
#endif

#ifndef DEBUG
#define PRINT_VALUE(v)
#define PRINT_ARRAY(arr,size)
#define DEBUG_PRINT(c)
#endif

const int MAX_N = 1e3+5;
int t,n;
int a[MAX_N],b[MAX_N];
vector<pair<int, int>> histories;

bool checkAllEleGoUp(){
    for(int i=2;i<=n;i++){
        if (a[i]<a[i-1]) {
            return false;
        }
    }
    return true;
}

void sort_fixed(){
    for(int i=1;i<=n;i++){
        int max_num=INT_MIN;
        vector<int> max_dirs;
        for (int j=i; j<=n; j++) {
            if (max_num<a[j]) {
                max_dirs.clear();
                max_num=a[j];
                max_dirs.push_back(j);
            }
        }
        int swap_dir=-1;
        for (int j=0; i<max_dirs.size(); i++) {
            if(b[max_dirs[j]]!=b[i]){
                swap_dir=max_dirs[j];
                break;
            }
        }
        if (swap_dir==-1) {
            histories.clear();
            return;
        }else {
            histories.push_back(make_pair(i, swap_dir));
        }
    }
}

signed main(){
    cin.sync_with_stdio(false);
    cin.tie(0);
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
        sort_fixed();
        if (histories.size()==0) {
            PRINT_VALUE(histories.size());
            cout<<-1<<endl;
        }else {
            cout<<histories.size()<<endl;
            for (auto v : histories) {
                cout<<v.first<<" "<<v.second<<endl;
            }
        }
    }
}