#include<bits/stdc++.h>
using namespace std;

#define PRINT_VALUE(v){cout<<#v<<" :"<<v<<"\n";}

int n, a[1005];
int cnt = 0;
int partition(int l, int r) {
    cnt += r-l+1;
    swap(a[l], a[(l+r)/2]);
    int i = l+1, j = r, x = a[l];
    while(1){
        while(a[i]<x && i<=r) i++;
        while(a[j]>x && j>=l+1) j--;
        if(i>=j) break;
        swap(a[i],a[j]);
        i++;j--;
    }
    swap(a[l],a[j]);
    return j; 
}

void qsort(int l, int r){
    if(l >= r) return;
    int m = partition(l,r);//分
    qsort(l,m-1);//解
    qsort(m+1,r);
}

int main(){
    n = 1000;
    for(int i=1;i<=n;i++) cin>>a[i];
    PRINT_VALUE(cnt);
    qsort(1,n);
    PRINT_VALUE(cnt);
    return 0;
}