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
        int p_min=-1;
        int min_num=arr[i];
        for (int j=i; j<=size; j++) {
            if (min_num>arr[j]){
                p_min=j;
                min_num=arr[j];
            }
        }
        if (p_min==-1) {
            continue;
        }else if(b[p_min]!=b[i]){
            hist.push_back(make_pair(p_min, i));
            swap(a[i],a[p_min]);
            swap(b[p_min],b[i]);
            continue;
        }else{
            int p_transfer;
            for (int j=1; j<=size;j++) {
                if (b[p_min]!=b[j]) {
                    p_transfer=j;
                    break;
                }
            }
            hist.push_back(make_pair(i, p_transfer));
            hist.push_back(make_pair(p_min, p_transfer));
            hist.push_back(make_pair(p_transfer, i));
            swap(a[i],a[p_min]);
            swap(b[i],b[p_min]);
            continue;
        }
    }
    cout<<hist.size()<<endl;
    for(auto [left,right]:hist){
        cout<<right<<" "<<left<<endl;
    }
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
        if (is_all_same(b, n)) {
            cout<<-1<<endl;
            continue;
        }
        sort_fix(a,b,n);
    }
}