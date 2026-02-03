//description
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // int minimumPairRemoval(vector<int>& nums){
    //     int n = nums.size();
    //     if(n <= 1) return 0;//edge case

    //     vector<long long> segments;
    //     int op = 0;

    //     for(int i = n-1; i >= 0; i--){
    //         long long curr = nums[i];

    //         while(!segments.empty() && curr > segments.back()){
    //             op++;
    //             curr += segments.back();
    //             segments.pop_back();
    //         }
    //         segments.push_back(curr);
    //     }
    //     return op;
    // }
    bool nonDecreasing(vector<int>& nums){//worked
        for(int i = 0; i < nums.size()-1; i++){
                if(nums[i] > nums[i+1]) return false;
        } return true;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int op = 0;
        while(!nonDecreasing(nums)){//fix it to sort
            int mini = INT_MAX;
            int index = -1;
            for(int i = 0; i < nums.size()-1; i++){
                int currSum = nums[i] + nums[i+1];
                if(currSum < mini){
                    mini = currSum;//update mini
                    index = i;//then only save index
                }
            }
            vector<int> temp;
            for (int i = 0; i < nums.size(); i++){
                if(i == index){
                    temp.push_back(mini);
                    i++;
                }
                else temp.push_back(nums[i]);
            }
            nums = temp;
            op++;
        }
        return op;
    }
};
int main(){
    vector<int> nums = {5, 2, 3, 1};
    Solution s;
    cout<<s.minimumPairRemoval(nums)<<endl;
    return 0;
}