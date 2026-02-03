#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int KadaneAlgorithm(vector<int>& arr){
        long long maxi = LLONG_MIN;
        long long sum = 0;
        for(int i = 0; i < arr.size(); i++){
            sum += arr[i];
            maxi = max(maxi,sum);
            if(sum < 0) sum = 0;
        }
        return maxi;
    }
    int maxCircularSum(vector<int> &arr) {
        // code here
        vector<int> temp = arr;
        int sum = INT_MIN;
        int maxi = INT_MIN;
        for(int i = 0; i < temp.size(); i++){
            sum = KadaneAlgorithm(temp);
            rotate(temp.begin(), temp.begin() + 1, temp.end());
            maxi = max(maxi, sum);
        }
        return maxi;
    }
};

int main(){
    vector<int> arr = {8, -8, 9, -9, 10, -11};
    Solution s;
    cout<<s.maxCircularSum(arr);
    return 0;
}