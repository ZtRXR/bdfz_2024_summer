# bdfz_2024_summer
# 题目经验总结
## Day2
### [U111091 区间2段覆盖](./day2/U111091/U111091.md)
1. 不要以小单位的路段为前缀和最小单位，要以房屋为前缀和最小单位\

## Day3
### [U86432 捞鱼(fish)](./day3/U86432/U86432.md)
1. 数据离散化是指把数据只保留有用的东西，在本题当中指的是把数据排序后保存顺序关系，让内存数组可以少一些
2. 看到哪个东西的数据量最少，实在不行就从那个东西下手

### [T490194 还原排列](./day3/T490194/T490194.md)
1. 学会使用`bool next_permutation(begin,end)` 进行排列组合，没有下一个组合时会返回false，下面是一个示例
```cpp
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
```

## Day4
### [T435167 01 Sort](./day4/T435167/T435167.md)
#### 通过异色中转
#### 环

## Day5
### 需要学习的点
#### 区间最值
#### 弄懂分数取模出现很大的数字是什么鬼、
1. >费马小定理
2. >逆元
```cpp
// a/b%M
ll _ksm(ll a, ll b,ll M){
    ll res = 1;
    while(b) {
        if(b & 1)                    
            res = res * a % M;       
        a = a * a % M;               
        b >>= 1;                     
    }
    return res;
}

ll ksm(ll a,ll b,ll M){
    return a * _ksm(b, M - 2,M) % M;
}
```
### 比赛疑问
#### [公平的竞争（fair）](./day5/statement.pdf)
##### $x=2+ {{x}\over{4}}$  => $x = {{8} \over 3}$是怎么得出来的

# 排序
## 稳定性
>隔着老远swap一般不稳定
>稳定：插入，归并，冒泡

# 竞赛的一些方法

1. 真正难的地方是通过题目给的信息和性质推出要用的算法
