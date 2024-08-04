#include<bits/stdc++.h>
using namespace std;
typedef unsigned int u32;
ostream& operator<<(ostream &os,const vector<int> &v){
    os<<"vector<int> [";
    for(u32 i=0;i<v.size();i++){
        os<<v[i]<<(i!=v.size()-1?",":"]");
    }
    return os;
}
int n;
int main(){
    cin>>n;
    vector<int> v(n);
    for(int &i:v){
        cin>>i;
    }
    cout<<"v:"<<v<<endl;
    while(next_permutation(v.begin(),v.end())){
        cout<<"v_pered"<<v<<endl;
    }
    
}