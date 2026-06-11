/*
you are given an integer array nums. A subarray is called balanced if the number of distinct even numbers in the subarray is equal to the number of distinct odd numbers. Return the length of the longest balanced subarray.

Constraints:
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^5

Hints:
Store the first (or all) occurrences for each value in pos[val].
Build a lazy segment tree over start indices l in [0..n-1] that supports range add and can tell if any index has value 0 (keep mn/mx).
Use sign = +1 for odd values and sign = -1 for even values.
Initialize by adding each value's contribution with update(p, n-1, sign) where p is its current first occurrence.
Slide left l: pop pos[nums[l]], let next = next occurrence or n, do update(0, next-1, -sign), then query for any r >= l with value 0 and update ans = max(ans, r-l+1).
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        auto get_sign = [](int x){ return (x & 1) ? 1 : -1; };

        // next[i] = next position > i with nums[i], or n
        vector<int> nxt(n, n);
        unordered_map<int, int> last;
        for (int i = 0; i < n; ++i) {
            if (last.count(nums[i])) {
                nxt[last[nums[i]]] = i;
            }
            last[nums[i]] = i;
        }

        // Segment tree: min and max value in range + lazy add
        // We keep current balance for each starting position
        vector<long long> tree(4*n), max_tree(4*n), lazy(4*n);

        auto push = [&](auto&& self, int v, int l, int r) -> void {
            if (lazy[v] != 0) {
                tree[v] += lazy[v];
                max_tree[v] += lazy[v];
                if (l != r) {
                    lazy[2*v] += lazy[v];
                    lazy[2*v+1] += lazy[v];
                }
                lazy[v] = 0;
            }
        };

        auto update_range = [&](auto&& self, int v, int tl, int tr, int l, int r, long long add) -> void {
            push(self, v, tl, tr);
            if (l > r) return;
            if (tl == l && tr == r) {
                lazy[v] += add;
                push(self, v, tl, tr);
                return;
            }
            int tm = (tl + tr) / 2;
            self(self, v*2, tl, tm, l, min(r, tm), add);
            self(self, v*2+1, tm+1, tr, max(l, tm+1), r, add);
            tree[v] = min(tree[2*v], tree[2*v+1]);
        };

        auto has_zero = [&](auto&& self, int v, int tl, int tr, int l, int r) -> bool {
            push(self, v, tl, tr);
            if (l > r) return false;
            if (tl == l && tr == r) {
                return tree[v] <= 0 && max_tree[v] >= 0;
            }
            int tm = (tl + tr) / 2;
            return self(self, v*2, tl, tm, l, min(r, tm)) ||
                   self(self, v*2+1, tm+1, tr, max(l, tm+1), r);
        };

        // Initially add contribution of each distinct number
        unordered_map<int, int> first_occ;
        for (int i = 0; i < n; ++i) {
            int val = nums[i];
            if (!first_occ.count(val)) {
                first_occ[val] = i;
                update_range(update_range, 1, 0, n-1, i, n-1, get_sign(val));
            }
        }

        int ans = 0;

        for (int l = 0; l < n; ++l) {
            // check if any r >= l has balance 0
            if (has_zero(has_zero, 1, 0, n-1, l, n-1)) {
                // binary search the maximum r
                int low = l, high = n-1, best = l-1;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    if (has_zero(has_zero, 1, 0, n-1, l, mid)) {
                        best = mid;
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
                ans = max(ans, best - l + 1);
            }

            // remove contribution of nums[l] if it was first
            int val = nums[l];
            if (first_occ.count(val) && first_occ[val] == l) {
                int s = get_sign(val);
                int next_pos = nxt[l];
                // remove +s from [l .. next_pos-1]
                update_range(update_range, 1, 0, n-1, l, next_pos-1, -s);
                first_occ.erase(val);
            }
        }

        return ans;
    }
};

int main() {
    vector<int> arr = {2, 5, 4, 3};
    Solution s;
    cout << s.longestBalanced(arr) << endl; // Output: 4
    return 0;
}
