/*complementary means all (arr[i] + arr[n-1-i]) values are same*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int minMoves(vector<int>& arr, int limit){
        int n = arr.size();

        vector<int> diff(2*limit + 2, 0);

        for(int i = 0; i < n/2; i++){
            
            int a = arr[i];
            int b = arr[n-1-i];

            int minVal = min(a, b) + 1;
            int maxVal = max(a, b) + limit;

            //move = 2
            diff[2] += 2;
            diff[2*limit + 1] -= 2;

            //move = 1 for minVal to maxVal
            diff[minVal] += (-1);
            diff[maxVal + 1] -= (-1);

            //move = 0 for sum = a+b
            diff[a+b] += (-1);
            diff[a+b + 1] -= (-1);
        }

        int result = INT_MAX;

        for(int sum = 2; sum <= 2*limit; sum++){
            diff[sum] += diff[sum-1]; //cumulative sum
            result = min(diff[sum], result);
        }

        return result;
    }
};
int main(){
    vector<int> arr = {1, 2, 4, 3};
    int limit = 4;
    Solution s;
    cout<<s.minMoves(arr, limit);
    return 0;
}