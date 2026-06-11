/*2770. maximum number of jumps to reach n-1 index
return -1 when cann't reach
*/
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:

    int maximumjumps(vector<int>& nums, int target){
        int n = nums.size();

        //memoization
        vector<int> t(n+1, INT_MIN); // T.C. O(N^2)

        t[n-1] = 0;

        for(int i = n-2; i > 0; i--){
            for(int j = i+1; j < n; j++){
                if(abs(nums[i] - nums[j]) <= target){
                    int temp = 1 + t[j];
                    
                    t[i] = max(t[i], temp);
                }
            }
        }
        return t[0] < 0 ? -1 : t[0];
    }

    // int n;
    // int function(int i, vector<int>& nums, int target, vector<int>& t){
        
    //     if(i == n-1) return t[i] == 0; // reached target
        
    //     if(t[i] !=  INT_MIN) return t[i];
        
    //     int ans = INT_MIN;
    //     for(int j = i+1; j < n; j++){
    //         if(abs(nums[i] - nums[j])  <= target){
    //             int temp = 1 + function(j, nums, target, t);
    //             ans = max(ans, temp);
    //         }
    //     }
    //     return t[i] = ans;
    // }

    // int maximumjumps(vector<int>& nums, int target){
    //     n = nums.size();

    //     //memoization
    //     vector<int> t(n+1, INT_MIN); // T.C. O(N^2)
    //     int ans = function(0, nums, target, t);

    //     return ans < 0 ? -1 : ans;
    // }
};
int main(){
    vector<int> arr = {1, 3, 6, 4, 1, 2};
    int target = 3;
    Solution s;
    cout<<s.maximumjumps(arr, target);
    return 0;
}