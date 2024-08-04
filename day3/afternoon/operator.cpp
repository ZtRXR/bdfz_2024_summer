#include <bits/stdc++.h>
#define uint unsigned int
using std::cout,std::vector,std::endl;

template<typename T>
std::ostream& operator<<(std::ostream& os,vector<T> &v){
    os<<"vector<?> [";
    for(size_t i=0;i<v.size();i++){
        os<<v[i]<<(i!=v.size()-1?",":"]\n");
    }
    return os;
}

std::ostream& operator<<(std::ostream& os,vector<int> &v){
    os<<"vector<int> [";
    for(size_t i=0;i<v.size();i++){
        os<<v[i]<<(i!=v.size()-1?",":"]\n");
    }
    return os;
}

int main(){
    vector<int> v(10);
    for(uint i=0;i<v.size();i++){
        v[i]=i;
    }
    cout<<v<<endl;
    vector<std::string> vs;
    vs.push_back("123");
    vs.push_back("1024");
    cout<<vs<<endl;
}