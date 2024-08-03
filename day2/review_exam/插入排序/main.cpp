#include <bits/stdc++.h>
using namespace std;

#define PRINT_VEC(v){\
    cout<<"\n"<<#v<<" [";\
    for(size_t i=0;i<v.size();i++){\
        cout<<v[i]<<(i!=v.size()-1?",":"]\n");\
    }\
}

#define PRINT_VALUE(v){\
    cout<<"\n"<<#v<<": "<<v<<"\n";\
}

void sort_fix(vector<int> &v){
    for (size_t i=1; i<v.size(); ++i) {
        PRINT_VALUE(i)
        int key=v[i];
        int j=i-1;
        while(j>=0&&v[j]>key){
            v[j+1]=v[j];
            --j;
        }
        v[j+1]=key;
        PRINT_VALUE(v[j+1])
    }
}

int main(){
    unsigned int n;
    cin>>n;
    vector<int> v(n);
    for(int &i:v){
        cin>>i;
    }
    PRINT_VEC(v);
    sort_fix(v);
    PRINT_VEC(v);
}