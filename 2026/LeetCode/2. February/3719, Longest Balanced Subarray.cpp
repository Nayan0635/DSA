/*
balanced if the number of distinct even numbers is 
equal to the number of distinct odd numbers.
Return the length of the longest balanced subarray.
Constraints:
1 <= nums.length <= 1500
1 <= nums[i] <= 105
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int longestBalanced(vector<int>& nums){
        int n = nums.size();
        unordered_map<int, int> prefixMap;
        prefixMap[0] = -1;
        int sum = 0;
        int maxlen = 0;
        for(int i = 0; i < n; i++){
            sum += (nums[i] % 2 == 0) ? 1 : -1;
            if(prefixMap.find(sum) != prefixMap.end()){
                maxlen = max(maxlen, i - prefixMap[sum]);
            } else {
                prefixMap[sum] = i;
            }
        }
        return maxlen;
    }
};
int main(){
    vector<int> arr = {1, 2, 3, 2};
    Solution s;
    cout<<s.longestBalanced(arr);
    return 0;
}