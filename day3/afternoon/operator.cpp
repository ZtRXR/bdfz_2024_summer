#include <bits/stdc++.h>
using std::cout,std::cin,std::vector,std::endl;

std::ostream& operator<<(std::ostream& os,vector<int> &v){
    os<<"vector<int> [";
    for(size_t i=0;i<v.size();i++){
        os<<v[i]<<(i!=v.size()-1?",":"]\n");
    }
    return os;
}

int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    cout<<v<<endl;
}