#include <bits/stdc++.h>
using namespace std;

#define PRINT_VEC(v){\
    cout<<#v<<" [";\
    for(size_t i=0;i<v.size();i++){\
        cout<<v[i]<<(i!=v.size()-1?",":"]\n");\
    }\
}

void sort_fix(vector<int> &v){
    for(size_t i=0;i<v.size()-1;i++){
        for(size_t j=i;j<v.size()-i-1;j++){
            if (v[j]>v[j+1]) {
                swap(v[j],v[j+1]);
            }
        }
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