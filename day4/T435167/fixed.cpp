//TODO
#include<bits/stdc++.h>
using namespace std;

const int MAX_N=1e3+5;
int t,n;
int a[MAX_N],b[MAX_N];

bool is_all_go_up(int a[],int size){
    for (int i=2; i<=size; i++) {
        if (a[i-1]>a[i]) {
            return false;
        }
    }
    return true;
}

bool is_all_same(int a[],int size){
    for(int i=2;i<=size;i++){
        if (a[i]!=a[1]) {
            return false;
        }
    }
    return true;
}

void sort_fix(int arr[],int b[],int size){
    vector<pair<int,int>> hist;
    for (int i=1; i<=size; i++) {
        int p_max=-1;
        int max_num=arr[i];
        for (int j=i; j<=size; j++) {
            if (max_num<arr[j]){
                p_max=j;
                max_num=arr[j];
            }
        }
        if (p_max==-1) {
            continue;
        }
        if(arr[p_max]!=arr[i]){
            hist.push_back(make_pair(p_max, i));
            swap(a[i],a[p_max]);
            swap(b[p_max],b[i]);
        }
    }
    //TODO
}

int main(){
    cin.sync_with_stdio(false);
    cin.tie(0);

    cin>>t;
    for (int i=1; i<=t; i++) {
        cin>>n;
        for (int j=1; j<=n; j++) {
            cin>>a[j];
        }
        for (int j=1; j<=n; j++) {
            cin>>b[j];
        }
        if (is_all_go_up(a, n)) {
            cout<<0<<endl;
            continue;
        }
        if (is_all_same(a, n)) {
            cout<<-1<<endl;
            continue;
        }
        sort_fix(a,b,n);
    }
}