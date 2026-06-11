/*
1 <= tasks.length() <= 10^4
1 <= actual <= minimum <= 10^5

at worst case requirement can be 10^4*10^5

(minimum - actual) this difference is important, it tells you how ,uch will be left 
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:

    bool isPossible(vector<vector<int>>& tasks, int mid){
        for(auto& t : tasks){
            int actual = t[0];
            int minimum = t[1];

            if(minimum > mid) return false;

            mid -= actual;
        }
        return true;
    }


    //binary search on answer
    int minimumEffort(vector<vector<int>>& tasks){
        int n = tasks.size();

        int l = 0;
        int r = 1e9;

        int result = INT_MAX;

        auto lamda = [](auto& task1, auto& task2){
            int diff1 = task1[1] - task1[0];
            int diff2 = task2[1] - task2[0];

            return diff1 > diff2;
        };

        sort(begin(tasks), end(tasks), lamda);

        while(l <= r){
            int mid = l + (r-l)/2;

            if(isPossible(tasks, mid)){
                result = mid;
                r = mid-1;
            }else{
                l = mid + 1;
            }
        }
        return result;
    }
};
int main(){
    vector<vector<int>> arr = {{1, 2}, {2, 4}, {4, 8}};
    Solution s;

    cout<<s.minimumEffort(arr);
    return 0;
}