//agressive cows (the minimum distance between any two them should be maximum)
#include<iostream>
#include<vector>
#include<algorithm>
//#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool canWePlace(vector<int> &list, int cows, int dist){//check if we can place those many cows 
        int cntCows= 1, last = list[0];
        int s = list.size();
        for (int i = 1; i < s; i++){
            if (list[i] - last >= dist){
                cntCows++;
                last = list[i];
            }
            if (cntCows == cows) return true;
        }
        return false;
    }
    int agressiveCows(vector<int> &stalls, int k){
        int n = stalls.size();
        sort(stalls.begin(),stalls.end());//T.C. O(NlogN)
        int low = 1, high = stalls[n-1] - stalls[0];
        while (low < high){
            int mid = low + (high - low)/2;
            if(canWePlace(stalls, k, mid))
                low = mid + 1;
            else
                high = mid - 1;
        }
        return high;
    }
};
int main(){
    vector<int> vec = {0, 3, 5, 7, 9, 10};
    Solution s;
    int cows = 4;
    cout<<s.agressiveCows(vec,cows);
    return 0;
}//17/12/24