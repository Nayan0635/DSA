#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> funtion_name(vector<int>& nums){
        int n = nums.size();
        vector<int> result(n, 0);

        for(int i = 0; i < n; i++){
            if(nums[i] == 0) continue;
            int next = ((i + nums[i])%n + n)%n;
            result[i] = nums[next];
        }
        return result;
    }
};
int main(){
    vector<int> arr = {3, -2, 1, 7, 2};
    Solution s;
    vector<int> ans = s.funtion_name(arr);
    for (auto& it : ans){
       cout<<it <<" ";
    }cout<<endl;
    return 0;
}