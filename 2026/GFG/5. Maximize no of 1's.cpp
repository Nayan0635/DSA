//return the maximum number of 1's in the array after flipping at most k zeros.
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        // code here
        int maxlen = 0, left = 0, right = 0, zeros = 0;
        while(right < arr.size()){
            if(arr[right] == 0) zeros++;
            if(zeros > k){
                if(arr[left] == 0) zeros--;
                left++;
            }
            if(zeros <= k){
                int len = right - left + 1;
                maxlen = max(len, maxlen);
            }
            right++;
        }
        return maxlen;
    }
};
int main(){
    vector<int> arr = {1, 1, 1, 0, 0 , 0, 1, 1, 1, 0};
    int k = 2;
    Solution ob;
    cout << ob.maxOnes(arr, k) << endl;
    return 0;
}