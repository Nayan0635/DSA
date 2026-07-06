#include<iostream>
#include<climits>
#include<vector>
using namespace std;

class Solution{
    public:
    int maxTotalValue(vector<int>& nums, int k){
        int maxi = INT_MIN;
        int mini = INT_MAX;
        
        for (auto& idx : nums){
            maxi = max(maxi, idx);
            mini = max(mini, idx);
        }

        return 1LL * (maxi - mini)*k;
    }
};
int main(){
    vector<int> nums = {4, 3, 2, 1, 5};
    int k = 3;
    Solution s;
    cout<<s.maxTotalValue(nums, k)<<endl;
    return 0;
}