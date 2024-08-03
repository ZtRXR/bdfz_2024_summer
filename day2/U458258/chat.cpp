#include <iostream>
#include <vector>

const int MOD = 1000000007;

// 快速幂计算
long long mod_pow(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// 计算前缀和
void compute_prefix_sum(const std::vector<int>& array, std::vector<long long>& prefix) {
    int n = array.size();
    prefix[0] = 0;
    for (int i = 1; i <= n; ++i) {
        prefix[i] = (prefix[i - 1] + array[i - 1]) % MOD;
    }
}

// 计算所有子区间平均数之和
long long calculate_average_sum(int n, const std::vector<int>& array) {
    std::vector<long long> prefix(n + 1, 0);
    compute_prefix_sum(array, prefix);
    
    // 预处理每个长度的逆元
    std::vector<long long> inverse(n + 1);
    for (int i = 1; i <= n; ++i) {
        inverse[i] = mod_pow(i, MOD - 2, MOD);
    }
    
    long long total_avg_sum = 0;
    for (int l = 0; l < n; ++l) {
        for (int r = l; r < n; ++r) {
            long long subarray_sum = (prefix[r + 1] - prefix[l] + MOD) % MOD;
            int length = r - l + 1;
            long long avg = (subarray_sum * inverse[length]) % MOD;
            total_avg_sum = (total_avg_sum + avg) % MOD;
        }
    }
    
    return total_avg_sum;
}

int main() {
    int t;
    std::cin >> t;
    std::vector<long long> results;
    
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> array(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> array[i];
        }
        results.push_back(calculate_average_sum(n, array));
    }
    
    for (long long result : results) {
        std::cout << result << std::endl;
    }
    
    return 0;
}
