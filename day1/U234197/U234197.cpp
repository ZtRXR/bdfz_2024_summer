#include <algorithm>
#include<bits/stdc++.h>
#include <iostream>
#include <ostream>

const int MAX_N{1000'000};
int n;
int a[MAX_N];
int cnt{0};


int main(){
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    std::cin>>n;
    for(unsigned i=0;i<n;i++){
        std::cin>>a[i];
    }
    for(unsigned l{0};l<n;l++){
        int max_num = INT_MIN;
        for (unsigned r{l};r<n;r++) {
            max_num = std::max(a[r],max_num);
            cnt+=max_num;
        } 
    }
    std::cout<<cnt<<"\n";
}