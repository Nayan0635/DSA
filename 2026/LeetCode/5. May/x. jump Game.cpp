/*
3 <= nums.size() <= 10^4
0 <= nums[i] <= 10^5
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int t[10001];
    bool solve(vector<int>& nums, int n, int ind){
        if(ind >= n-1)
            return true;

        if(t[ind] != -1)
            return t[ind];
        
        for(int i = 1; i <= nums[ind]; i++){
            if(solve(nums, n, ind + i))
                return t[ind] = 1;
        }
        return t[ind] = 0;
    }


    bool canJump(vector<int> &nums){
        int n = nums.size();
        memset(t, -1, sizeof(t));
        return solve(nums, n, 0);
    }
};
int main(){
    vector<int> nums = {2, 3, -1, 1, 4};
    Solution s;
    cout<<s.canJump(nums);
    return 0;
}