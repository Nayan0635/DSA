//Indexes of Subarray Sum
#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    vector<int> subarraySum(vector<int> &arr, int target){
        int n = arr.size();
        int left = 0, sum = 0;
        vector<int> ans;
        for (int right = 0; right < n; right++){
            sum+=arr[right];
            while (sum > target && left<= right){
                //trim down from left untile and unless it's <= target
                sum-= arr[left];
                left++;
            }
            if (sum == target){//push the indexes and return 
                ans.push_back(left+1);
                ans.push_back(right+1);
                return ans;
            }
        }
        return {-1};
    }
};
int main(){
    vector<int> vec = {1, 2, 3, 7, 5};
    int t = 12;
    Solution s;
    cout<<"["<<s.subarraySum(vec, t)[0]<<","<<s.subarraySum(vec, t)[1]<<"]";
    return 0;
}
//09/01/25