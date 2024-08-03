#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

long long calculateInitialDirtLength(int n, const vector<int>& x, const string& road_types) {
    long long dirt_length = 0;
    int start = -1;

    for (int i = 0; i < n - 1; ++i) {
        if (road_types[i] == '1') {
            if (start == -1) start = i;
        } else {
            if (start != -1) {
                dirt_length += x[i + 1] - x[start];
                start = -1;
            }
        }
    }

    if (start != -1) {
        dirt_length += x[n - 1] - x[start];
    }

    return dirt_length;
}

long long getMaxReduction(const vector<pair<int, int>>& dirt_segments, int m) {
    long long max_reduction = 0;
    int l = 0, n = dirt_segments.size();
    vector<long long> prefix_sums(n + 1, 0);

    for (int i = 0; i < n; ++i) {
        prefix_sums[i + 1] = prefix_sums[i] + dirt_segments[i].second - dirt_segments[i].first;
    }

    for (int r = 0; r < n; ++r) {
        while (dirt_segments[r].second - dirt_segments[l].first > m) {
            ++l;
        }
        long long current_reduction = prefix_sums[r + 1] - prefix_sums[l];
        long long total_length = dirt_segments[r].second - dirt_segments[l].first;
        if (total_length > m) {
            current_reduction -= (total_length - m);
        }
        max_reduction = max(max_reduction, current_reduction);
    }

    return max_reduction;
}

long long solveCase(int n, int k, int m, const vector<int>& x, const string& road_types) {
    long long initial_dirt_length = calculateInitialDirtLength(n, x, road_types);

    vector<pair<int, int>> dirt_segments;
    int start = -1;

    for (int i = 0; i < n - 1; ++i) {
        if (road_types[i] == '1') {
            if (start == -1) start = i;
        } else {
            if (start != -1) {
                dirt_segments.emplace_back(start, i);
                start = -1;
            }
        }
    }

    if (start != -1) {
        dirt_segments.emplace_back(start, n - 1);
    }

    if (k == 1) {
        return initial_dirt_length - getMaxReduction(dirt_segments, m);
    }

    long long best = 0;
    for (int i = 0; i < dirt_segments.size(); ++i) {
        auto first_segment = dirt_segments[i];
        vector<pair<int, int>> temp_segments;
        for (int j = 0; j < dirt_segments.size(); ++j) {
            if (j != i) temp_segments.push_back(dirt_segments[j]);
        }
        long long first_reduction = getMaxReduction(vector<pair<int, int>>{first_segment}, m);
        long long second_reduction = getMaxReduction(temp_segments, m);
        best = max(best, first_reduction + second_reduction);
    }

    return initial_dirt_length - best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n, k, m;
        cin >> n >> k >> m;
        vector<int> x(n);
        for (int i = 0; i < n; ++i) cin >> x[i];
        string road_types;
        cin >> road_types;

        cout << solveCase(n, k, m, x, road_types) << endl;
    }

    return 0;
}
