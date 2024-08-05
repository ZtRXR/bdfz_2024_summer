#include<bits/stdc++.h>
#define MAXN 200005
#define P int(1e9+7)
using namespace std;
typedef long long ll;
/*
U111091 区间2段覆盖
先看k==1的情况：
观察1：
存在最优区间以某个村庄作为终点
那么做法就是枚举终点，维护一个指针指向起点，计算答案即可，复杂度 。
当k==2时，需要考虑两种情况：
1. 第一个区间终点和第二个区间起点在同一条道路内
2. 否则，存在一个分界村庄i，2条道路分别在i之前和i之后
观察2：
若2个选定区间的端点在同一条道路内，则存在最优方案使得它们首尾相连
调整法可以证明，所以case1，就当作 做；
对于case2，分别dp之后维护前缀/后缀max，枚举分界点 即可。
总复杂度线性

*/
int T,N,K,q;
int x[MAXN], sum = 0;
int g[MAXN], pre[MAXN], suf[MAXN];
char s[MAXN];
int solve1(int q)//解决优化一段长度为q的土路的情况
{
	int k = 1;//一段路的开始位置
	int ans = 0;//能优化的最长的土路的长度
	int ans1;
	for(int i=2;i<=N;i++)
	{
		while(x[i]-x[k]>q) 
			k++;
		ans1 = g[i] - g[k]; //第k个村庄到第i个村庄之间土路的长度
		if(s[k]=='1') 
			ans1 += q - (x[i]-x[k]);
		ans = max(ans, ans1);
	}
//cerr<<"ans1 = "<<ans1<<endl;
	return ans;
}
int solve2(int q)//计算找两段长度为q的土路，最多能改变多少变成高速公路
{
	memset(pre, 0, sizeof(pre));
	memset(suf, 0, sizeof(suf));

	int ans1;
	int k = 1;//一段路的开始位置
	for(int i=2;i<=N;i++){
		while(x[i]-x[k]>q) ++k;
		ans1 = g[i] - g[k];
		if(s[k]=='1') 
			ans1 += q - (x[i]-x[k]);
		pre[i] = max(pre[i-1], ans1);
	}
	k = N;
	for(int i=N-1;i>=1;i--){
		while(x[k]-x[i]>q) 
			--k;
		ans1 = g[k] - g[i];
		if(s[k+1]=='1') 
			ans1 += q - (x[k]-x[i]);
		suf[i] = max(suf[i+1], ans1);
	}
	int ans = 0;
	for(int i=2;i<=N;i++){
		ans = max(ans, pre[i] + suf[i]);
	}
	return ans;
}
int main(){
	cin>>T;
	while(T--){
		cin>>N>>K>>q;
		for(int i=1;i<=N;i++) 
			cin>>x[i];
		cin>>s+2;
		s[1] = '0';
		sum = 0;//土路总长度
		for(int i=2;i<=N;i++){
			g[i] = g[i-1];//前i个村庄之间土路的总长度
			if(s[i]=='1')//i-1到i村庄之间的路是土路	
			{
				g[i] += x[i] - x[i-1];
				sum += x[i] - x[i-1];
			}
		}
		int ans;
		if(K==1) 
			ans = sum - solve1(q);
		else 
			ans = sum - max(solve1(2*q), solve2(q));
		cout<<ans<<'\n';
	}
	return 0;
}

