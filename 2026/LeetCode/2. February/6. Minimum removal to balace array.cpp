#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int l = 0, r = 0;
        int best = 1;   // at least 1 element is always valid

        while (r < n) {
            // shrink window if invalid
            while (nums[r] > 1LL * k * nums[l]) {
                l++;
            }

            best = max(best, r - l + 1);
            r++;
        }

        return n - best;
    }
};
int main(){
    Solution sol;
    vector<int> nums = {1,6,2,9};
    int k = 3;
    cout << sol.minRemoval(nums, k) << endl;
    return 0;
}