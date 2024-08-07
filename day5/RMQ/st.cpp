#include<bits/stdc++.h>
using namespace std;

#define PRINT_VALUE(v){cout<<#v<<" :"<<v<<endl;}

struct SparseTable{
private:
    vector<vector<int>> st;
    vector<int> log;
    int n;
public:
    SparseTable(const vector<int> &arr){
        n=arr.size();
        int K=log2(n)+1;
        st.assign(n,vector<int>(K));
        log.assign(n+1,0);

        log[1]=0;
        for(int i=2;i<=n;i++){
            log[i]=log[i/2]+1;
        }
        for(int i=0;i<n;i++){
            st[i][0]=arr[i];
        }
        for(int j=1;j<=K;j++){
            for(int i=0;(i+(1<<j))<=n;i++){
                st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
            }
        }
    }
    int query(int l,int r){
        int j=this->log[r-l+1];
        return min(this->st[l][j],this->st[r-(1<<j)+1][j]);
                    //因为log[i]向下取整，所以此时r>=(1<<j)求右边的区间就是st[]
    }
};

int main(){
    vector<int> v={1, 3, 5, 7, 9, 11};
    SparseTable st_min(v);
    // PRINT_VALUE(st_min.query(1,2));
    PRINT_VALUE(st_min.query(1, 4));

}   

