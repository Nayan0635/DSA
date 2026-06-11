// leetcode 3637
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool isTrionic(vector<int>& nums){
        int i = 1;
        int n = nums.size();
        while(i < n && nums[i] > nums[i-1]){//increasing
            i++;
        }
        if(i == 1 || i == n-1) return false;
        while(i < n && nums[i] < nums[i-1]){//decreasing
            i++;
        }
        if(i == n) return false;
        while(i < n && nums[i] > nums[i-1]){//increasing
            i++;
        }
        if(i == n) return true;
        return false;
    }//
};

int main() {
    vector<int> arr = {1, 3, 5, 4, 2, 6};
    Solution s;
    cout<<boolalpha<<s.isTrionic(arr);
    return 0;
}