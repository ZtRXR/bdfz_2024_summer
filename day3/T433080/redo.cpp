#include<bits/stdc++.h>
using std::swap,std::cin,std::cout,std::ostream,std::endl,std::next_permutation;
typedef unsigned int u32;
typedef int i32;
typedef size_t usize;

#define PRINT_VALUE(v){cout<<#v<<" : "<<v<<endl;}

template<typename T,usize S>
struct Array{
    T arr[S];
    usize size;
    Array():size(S){};
    T& operator[](usize index){return arr[index];}
    const T& operator[](usize index)const{return arr[index];}
    friend ostream& operator<<(ostream &os,Array<T, S> &a){
        cout<<"Array<T,S> [";
        for(usize i=0;i<a.size;i++){
            cout<<a[i]<<(i!=a.size-1?",":"]");
        }
        return os;
    }
    T* begin(){
        return this->arr;
    }
    T* end(){
        return this->arr+this->size;
    }
};

int cnt = 0;
int partition(int l, int r,int a[]) {
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

void qsort(int l, int r,int a[]){
    if(l >= r) return;
    int m = partition(l,r,a);//分
    qsort(l,m-1,a);//解
    qsort(m+1,r,a);
}



int main(){
    const i32 n=5;
    Array<int, n+1> arr;
    for(usize i =1;i<arr.size;i++){
        arr[i]=i;
    }
    do{
        cnt=0;
        auto a=arr;
        PRINT_VALUE(a);
        qsort(1,a.size-1,a.begin());
        PRINT_VALUE(a);
        PRINT_VALUE(cnt);
        cout<<"-----------next  term---------\n";
    }while(next_permutation(arr.begin(),arr.end()));
}