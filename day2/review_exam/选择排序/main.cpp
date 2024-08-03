#include <bits/stdc++.h>
using namespace std;

#define PRINT_VEC(v){\
    cout<<"\n"<<#v<<" [";\
    for(size_t i=0;i<v.size();i++){\
        cout<<v[i]<<(i==v.size()-1?"]\n":",");\
    }\
}

int n;
void sort_fix(vector<int> &v){
    for(int i=0;i<v.size();i++){
        int min_num=INT_MAX;
        int min_dir=0;
        for (int j=i; j<v.size();j++) {
            if (min_num>v[j]) {
                min_num=v[j];
                min_dir=j;
            }
        }
        swap(v[i],v[min_dir]);
    }
}

int main(){
    cin>>n;
    vector<int> vec(n);
    for (size_t i=0; i<n; i++) {
        cin>>vec[i];
    }
    PRINT_VEC(vec)
    sort_fix(vec);
    PRINT_VEC(vec)
}