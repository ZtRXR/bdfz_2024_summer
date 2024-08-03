#include <bits/stdc++.h>
using namespace std;

//DEBUG
#define PRINT_VEC(vec) {\
    cout<<"\n"<<#vec<<" [";\
    for (size_t i=0; i<vec.size(); i++) {\
        cout<<vec[i]<<(i!=vec.size()-1?",":"]\n");\
    }\
}

#define int long long
// #define p_vec(n) cout<<"n"<<endl;



const int MAX_N = 1e6+6;
int n,m;


signed main(){
    cin>>n>>m;
    vector<int> a(n),b(n);
    for (int i=0; i<n; i++) {
        cin>>a[i];
    }
    PRINT_VEC(a)
    
    for (int i=0; i<n; i++) {
        cin>>b[i];
    }
    PRINT_VEC(b)
}