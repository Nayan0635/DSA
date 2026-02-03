//kth missing positive number in an sorted array
#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    int ktMissing(vector<int> &arr, int k){//BruteForce
        int n = arr.size();
        for (int i = 0; i < n; i++){
            if (arr[i] < k) k++;
            else            break;
        }
        return k;
    }
    int ktmissing(vector<int> &arr, int k){//Optimal
        int n = arr.size();
        int low = 0, high = n-1;
        while (low <= high){
            int mid = low + (high - low)/2;
            int missing = arr[mid] - (mid + 1);
            if (missing < k) //no of missing elements are less than required
                low = mid + 1;
            else
                high = mid - 1;
        }
        return (high + k + 1);
    }
};
int main(){
    vector<int> vec = {2,4,5,7,11};
    Solution s;
    cout<<s.ktmissing(vec,5);
    return 0;
}//19/12