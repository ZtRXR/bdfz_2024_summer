#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct Info {
    int l, r, val;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<Info> infos(m);
    for (int i = 0; i < m; ++i) {
        cin >> infos[i].l >> infos[i].r >> infos[i].val;
    }

    vector<int> p(n + 1, -1);
    vector<set<int>> mex_sets(n + 1);

    for (int i = 0; i <= n; ++i) {
        mex_sets[i].insert(0);
    }

    for (const auto& info : infos) {
        for (int i = info.l; i <= info.r; ++i) {
            if (info.val > 0) {
                mex_sets[i].erase(info.val - 1);
            }
            mex_sets[i].insert(info.val);
        }
    }

    for (int i = 0; i <= n; ++i) {
        if (p[i] == -1) {
            auto it = mex_sets[i].begin();
            p[i] = *it;
        }
    }

    bool valid = true;
    for (const auto& info : infos) {
        set<int> s;
        for (int i = info.l; i <= info.r; ++i) {
            s.insert(p[i]);
        }
        int expected_mex = 0;
        while (s.count(expected_mex)) {
            ++expected_mex;
        }
        if (expected_mex != info.val) {
            valid = false;
            break;
        }
    }

    if (valid) {
        for (int i = 0; i <= n; ++i) {
            cout << p[i] << " ";
        }
        cout << endl;
    } else {
        cout << "-1" << endl;
    }

    return 0;
}
