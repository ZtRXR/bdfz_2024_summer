#include<bits/stdc++.h>
using namespace std;
#define int long long

const int MAX_N = 10'0000;
int times;

int x[MAX_N];
int l[MAX_N];
int prefix_r[MAX_N];
int r[MAX_N];

// void debug_array(int array[],size_t size,string name){
//     cout<<"\n"<<name<<" [";
//     for(int i=0;i<size;i++){
//         cout<<array[i]<<(i!=size-1?",":"");
//     }
//     cout<<"]\n";
// }


signed main(){
    cin.sync_with_stdio(false);
    cin.tie(0);

    cin>>times;
    for(int t=1;t<=times;t++){

        int n,k,m;
        cin>>n>>k>>m;
        for (int i=1; i<=n; i++) {
            cin>>x[i];
        }

        string s;
        cin>>s;
        int sum=0,cnt=0;
        vector<int> v;
        int last0=1;
        for (int i=2; i<=n; i++) {
            if(s[i-2]=='0')
            {
                int dif=x[i-1]-x[last0];
                sum+=dif;
                cnt+=dif/m;
                v.push_back(dif%m);
                last0=i;
            }
        }
        int dif=x[n]-x[last0];
        sum+=dif;
        cnt+=dif/m;
        v.push_back(dif%m);
        sort(v.begin(),v.end(),greater<int>());
        if(k<=cnt)
        {
            sum-=k*m;
        }
        else
        {
            sum-=cnt*m;
            k-=cnt;
            for(int j:v)
            {
                if(k==0)
                {
                    break;
                }
                sum-=min(j,m);
                k--;
            }
        }
        cout<<sum<<"\n";
    }

}