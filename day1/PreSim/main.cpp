#include<bits/stdc++.h>
using namespace std;

string s1,s2,s3,s4,s5,s6;

int main() {
    s1 = "BDBBACBCABCACAA";
    s2 = "TTDAA";
    s3 = "FFAAA";
    s4 = "TTTAAA";
    s5 = "DCCC";
    s6 = "ABCBAA";
    
    string ans = s1 + s2 + s3 + s4 + s5 + s6;
    assert(ans.length() == 41);
    cout<<ans;
    return 0;
}