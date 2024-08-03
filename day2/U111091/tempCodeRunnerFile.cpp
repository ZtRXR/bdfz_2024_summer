#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 5'0000+5;
int times;
int n,k,m;
int x[MAX_N];
int l[MAX_N];
int prefix_r[MAX_N];
int r[MAX_N];
int max_house = INT_MIN;


int main(){
    cin.sync_with_stdio(false);
    cin.tie(0);

    cin>>times;
    for(int t=1;t<=times;t++){
        max_house = INT_MIN;
        prefix_r[0]=0;
        cin>>n>>k>>m;
        for (int i=1; i<=n; i++) {
            cin>>x[i];
            if (max_house<=x[i])max_house=x[i];
        }
        string s;
        cin>>s;
        assert(s.size()==n-1);
        for(int i=1;i<=s.size();i++){
            if (s[i-1]=='1') {
                l[i]=1;
                for (int j=x[i]+1; j<=x[i+1]; j++) {
                    r[j]=l[i];
                }
            }else {
                l[i]=0;
            }
        }
        for (int j=1; j<=k; j++) {
            for(int i=1;i<=max_house;i++){
                prefix_r[i]=prefix_r[i-1]+r[i];
            }
            int max_dir=INT_MIN;
            int max_num=INT_MIN;
            for (int i=1; i<=max_house-m; i++) {
                if (prefix_r[i+m]-prefix_r[i]>max_num) {
                    max_dir=i;
                    max_num=prefix_r[i+m]-prefix_r[i];
                }
            }
            //RM
            // cout<<"\nMAX_DIR:"<<max_dir<<"\n";
            for (int i=max_dir+1; i<=max_dir+m; i++) {
                r[i]=0;
            }

            int cnt=0;
            for (int i=1; i<=max_house; i++) {
                cnt+=r[i];
            }
            //RM
            // cout<<"\ncnt:"<<cnt<<"\n";

            cout<<cnt<<"\n";
        }
        //RM
        // cout<<"\nNEXT------------\n"<<endl;

        /*
        cout<<"\nl:\n";
        for(int i=1;i<=n;i++){
            cout<<l[i]<<",";
        }
        cout<<"\n";
        */
        

    }

}