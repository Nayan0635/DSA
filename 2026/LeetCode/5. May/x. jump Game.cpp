/*
3 <= nums.size() <= 10^4
0 <= nums[i] <= 10^5
*/

#include<bits/stdc++.h>
using namespace std;


class Solution{
    public:
    
    //optimal

    bool canJump(vector<int> &nums){
        int maxi = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(i > maxi)  return false;
            maxi = max(maxi, i + nums[i]);
            if(maxi == n-1) break;
        }
        return true;
    }


    //bottom up 

    // bool canJump(vector<int> &nums){
    //     int n = nums.size();
    //     vector<bool> t(n, false);
    //     t[0] = true;

    //     for(int i = 1; i < n; i++){
    //         for(int j = i-1; j > 0; j--){
    //             if(t[j] == true && j + nums[j] >= i){
    //                 t[i] = true;
    //                 break;
    //             }
    //         }
    //     }
    //     return t[n-1];
    // }

    //Recursion + Memoization  O(k^n)

    //public:
    //int t[10001];
    // bool solve(vector<int>& nums, int n, int ind){
    //     if(ind >= n-1)
    //         return true;

    //     if(t[ind] != -1)
    //         return t[ind];
        
    //     for(int i = 1; i <= nums[ind]; i++){
    //         if(solve(nums, n, ind + i))
    //             return t[ind] = 1;
    //     }
    //     return t[ind] = 0;
    // }


    // bool canJump(vector<int> &nums){
    //     int n = nums.size();
    //     memset(t, -1, sizeof(t));
    //     return solve(nums, n, 0);
    // }
};
int main(){
    vector<int> nums = {2, 3, -1, 1, 4};
    Solution s;
    cout<<s.canJump(nums);
    return 0;
}