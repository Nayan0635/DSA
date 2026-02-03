#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int mini = INT_MAX;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i = 0; i <= n-k; i++){
            mini = min(mini, nums[i+k-1] - nums[i]);
        }
        return mini;
    }
};
int main(){
    vector<int> arr = {9, 4, 1, 7};
    int k = 2;
    Solution s;
    cout<<s.minimumDifference(arr, k);
    return 0;
}