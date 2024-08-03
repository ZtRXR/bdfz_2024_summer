#include <bits/stdc++.h>
using namespace std;

#define PRINT_VEC(v) cout<<#v<<" [";for(size_t i=0;i<v.size();i++)cout<<v[i]<<(i!=v.size()-1?",":"]\n");

void sort_fix(vector<int> &v){
    for(size_t i=0;i<v.size()-1;i++){
        for(size_t j=0;j<v.size()-i-1;j++){
            if(v[j]>v[j+1]){
                swap(v[j],v[j+1]);
            }
        }
    }
}

int main(){
    unsigned int n;
    cin>>n;
    vector<int> my_vector(n);
    for(int &i:my_vector){
        cin>>i;
    }
    PRINT_VEC(my_vector)
    sort_fix(my_vector);
    PRINT_VEC(my_vector)
}