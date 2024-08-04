这个问题要求我们根据给定的若干条信息，重建一个 $0 \sim n$ 的排列 $p$。这些信息描述了某些区间的 ${\rm mex}$ 值。${\rm mex}$ 是指最小的没有在该区间内出现的非负整数。

我们需要根据这些条件构造一个满足所有信息的排列，或者判断是否无解。

## 问题分析和思路

1. **理解 ${\rm mex}$ 的定义**:
   ${\rm mex}$ (minimum excluded value) 是一个区间中未出现的最小非负整数。例如，在区间 `[0, 2, 3]` 中，${\rm mex}$ 是 `1`，因为 `1` 是未出现的最小非负整数。

2. **信息的限制**:
   给定若干条信息，每条信息形如 `(l, r, val)`，表示区间 `[l, r]` 的 ${\rm mex}$ 值为 `val`。

3. **构造思路**:
   - 初始化一个大小为 `n+1` 的数组 `p`，所有元素初始化为 `-1`，表示未被确定的值。
   - 遍历给定的所有区间信息，逐步填充数组 `p`。
   - 检查每个区间的 ${\rm mex}$ 信息，确保填充的值符合所有给定的条件。

4. **区间处理**:
   - 我们需要确保在给定区间 `[l, r]` 中，`val` 是该区间中未出现的最小非负整数。
   - 使用区间处理算法（如线段树或差分数组）来高效地处理和验证区间信息。

## 详细算法步骤

1. **初始化**:
   - 创建数组 `p`，大小为 `n+1`，所有元素初始化为 `-1`。
   - 创建一个辅助数组 `fixed`，大小为 `n+1`，用于标记哪些位置已经被确定。

2. **处理区间信息**:
   - 对于每条信息 `(l, r, val)`:
     - 确保区间 `[l, r]` 中没有比 `val` 更小的未出现的非负整数。
     - 如果在处理过程中发现矛盾（如 `val` 已经在区间内出现但仍被认为是未出现的最小非负整数），则判定无解。

3. **验证和填充**:
   - 遍历数组 `p`，确保所有位置都被有效填充。
   - 如果有未填充的位置，则根据已知信息进行推断和填充。

4. **输出结果**:
   - 如果构造成功，输出数组 `p`。
   - 如果无法构造，输出 `-1`。

## C++ 实现

```cpp
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
```

这个实现利用了 `set` 结构来动态维护每个位置的可能 `mex` 值，并在最后一步进行验证。如果验证通过，则输出构造的排列；如果不通过，则输出 `-1` 表示无解。

此实现的时间复杂度大约是 $O(nm)$，因为需要遍历每个区间的信息，并对每个位置的 `mex` 进行维护。对于较大的输入数据，可能需要进一步优化。