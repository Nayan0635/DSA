
// You are given a 0-indexed array of integers nums of length n, and two positive integers k and dist.
// The cost of an array is the value of its first element. For example, the cost of [1,2,3] is 1 while the cost of [3,4,1] is 3.
// You need to divide nums into k disjoint contiguous subarrays, such that the difference between the starting index of the second subarray and the starting index of the kth subarray should be less than or equal to dist. In other words, if you divide nums into the subarrays nums[0..(i1 - 1)], nums[i1..(i2 - 1)], ..., nums[ik-1..(n - 1)], then ik-1 - i1 <= dist.

// Return the minimum possible sum of the cost of these subarrays.

// Input: nums = [1,3,2,6,4,2], k = 3, dist = 3
// Output: 5
// Explanation: The best possible way to divide nums into 3 subarrays is: [1,3], [2,6,4], and [2]. This choice is valid because ik-1 - i1 is 5 - 2 = 3 which is equal to dist. The total cost is nums[0] + nums[2] + nums[5] which is 1 + 2 + 2 = 5.
// It can be shown that there is no possible way to divide nums into 3 subarrays at a cost lower than 5.

/*
Constraints:

3 <= n <= 105
1 <= nums[i] <= 109
3 <= k <= n
k - 2 <= dist <= n - 2
*/


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        multiset<long long> small, large;
        long long sumSmall = 0;
        long long ans = LLONG_MAX;

        auto add = [&](long long x) {
            small.insert(x);
            sumSmall += x;
            if ((int)small.size() > k - 1) {
                auto it = prev(small.end());
                sumSmall -= *it;
                large.insert(*it);
                small.erase(it);
            }
        };

        auto remove = [&](long long x) {
            auto it = small.find(x);
            if (it != small.end()) {
                sumSmall -= *it;
                small.erase(it);
                if (!large.empty()) {
                    auto it2 = large.begin();
                    sumSmall += *it2;
                    small.insert(*it2);
                    large.erase(it2);
                }
            } else {
                large.erase(large.find(x));
            }
        };

        // Initial window [1 .. dist+1]
        for (int i = 1; i <= dist + 1; i++) {
            add(nums[i]);
        }
        ans = min(ans, sumSmall);

        // Slide window
        for (int i = dist + 2; i < nums.size(); i++) {
            remove(nums[i - dist - 1]);
            add(nums[i]);
            ans = min(ans, sumSmall);
        }

        return nums[0] + ans;
    }
};
int main(){
    vector<int> nums = {1,3,2,6,4,2};
    int k = 3;
    int dist = 3;
    Solution s;
    cout<<s.minimumCost(nums, k, dist);
    return 0;
}
