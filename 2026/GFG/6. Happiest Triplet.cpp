#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> smallestDiff(vector<int>& a, vector<int>& b, vector<int>& c) {
        // code here.
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());
        
        int i = 0, j = 0, k = 0;
        long long minSum = LLONG_MAX;
        long long minDiff = LLONG_MAX;
        int x = -1, y = -1, z = -1;
        
        while (i < a.size() && j < b.size() && k < c.size()) {
            int mini = min({a[i], b[j], c[k]});
            int maxi = max({a[i], b[j], c[k]});
            
            long long diff = (long long)maxi - mini;
            long long sum = (long long)a[i] + b[j] + c[k];
            
            if ((diff < minDiff) || (diff == minDiff && sum < minSum)) {
                minDiff = diff;
                minSum = sum;
                x = a[i];
                y = b[j];
                z = c[k];
            }
            
            if (mini == a[i]) i++;
            else if (mini == b[j]) j++;
            else k++;
        }
        
        vector<int> ans = {x, y, z};
        sort(ans.begin(), ans.end(), greater<int>());
        
        return ans;
    }
};

int main(){
    vector<int> a = {15, 12, 18, 9};
    vector<int> b = {10, 17, 13, 8};
    vector<int> c = {14, 16, 11, 5};
    
    Solution ob;
    vector<int> result = ob.smallestDiff(a, b, c);
    
    for (int num : result) {
        cout << num << " ";
    }cout << endl;
    
    return 0;   
}
