/*return the minimum integer k such
that koko can eat all bananas in h hours
*/
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int function(vector<int>& arr, int hourly){
        int totalHour = 0;
        int n = arr.size();
        for(int i = 0; i < n; i++){
            totalHour += (arr[i] + hourly - 1) / hourly;
        }
        return totalHour;
    }

    int kokoEat(vector<int>& arr, int h){//binary search
        int maxi = *max_element(arr.begin(), arr.end());
        int low = 1, high = maxi;
        int mid;
        while(low <= high){
            mid = low + (high - low)/2;
            int reqtime = function(arr, mid);
            if(reqtime <= h){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return low; //T.C. O(nlog(max(arr))) S.C. O(1)
    }
};
int main(){
    vector<int> arr = {3, 6, 7, 11};
    int hour = 8;
    Solution s;
    cout<<s.kokoEat(arr, hour);
    return 0;
}