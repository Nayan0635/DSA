#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int maxProduct(vector<int>& arr){
        int maxi = INT_MIN;
        int pref = 1, suff = 1;
        int n = arr.size();
        for(int i = 0; i < n; i++){
            if(pref == 0) pref = 1;
            if(suff == 0) suff = 1;
            pref = pref * arr[i];
            suff = suff * arr[n-1-i];
            maxi = max(maxi, max(pref, suff));
        }
        return maxi;
    }
};

int main(){
    vector<int> arr = {2, 3, -2, 4};
    Solution s;
    cout<<s.maxProduct(arr);
    return 0;
}