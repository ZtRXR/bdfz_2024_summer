#include<bits/stdc++.h>
using namespace std;


#define PRINT_VEC(v){\
    cout<<#v<<" [";\
    for(size_t i=0;i<v.size();i++){\
        cout<<v[i]<<(i!=v.size()-1?",":"]\n");\
    }\
}

void sort_fix(vector<int> &v){
    for(size_t i=0;i<v.size();i++){
        int min_num=INT_MAX;
        size_t min_dir=0;
        for(size_t j=i;j<v.size();j++){
            if(min_num>v[j]){
                min_num=v[j];
                min_dir=j;
            }
        }
        swap(v[i],v[min_dir]);
    }
}

int main(){
    size_t n;
    cin>>n;
    vector<int> v(n);
    for(int &i:v){
        cin>>i;
    }
    PRINT_VEC(v);
    sort_fix(v);
    PRINT_VEC(v);
}