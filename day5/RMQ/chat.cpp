#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class SparseTable {
private:
    vector<vector<int>> st;
    vector<int> log;
    int n;

public:
    SparseTable(const vector<int>& arr) {
        n = arr.size();
        int K = log2(n) + 1;
        st.assign(n, vector<int>(K));
        log.assign(n + 1, 0);//为什么要n+1

        // 初始化 log 数组
        log[1] = 0;
        for (int i = 2; i <= n; ++i) {
            log[i] = log[i / 2] + 1;
        }

        // 初始化 st 数组
        for (int i = 0; i < n; ++i) {
            st[i][0] = arr[i];
        }

        // 动态规划填充 st 数组
        for (int j = 1; j <= K; ++j) {
            for (int i = 0; (i + (1 << j)) <= n; ++i) {
                st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);//为什么是j-1?
            }
        }
    }

    int query(int L, int R) {
        int j = log[R - L + 1];
        return min(st[L][j], st[R - (1 << j) + 1][j]);
    }
};

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    SparseTable sparseTable(arr);
    cout << "Min value in range [1, 4]: " << sparseTable.query(1, 4) << endl;
    return 0;
}
