#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        // code here
        int result = 0;
        if(!left.empty()){
            result = max(result, *max_element(left.begin(), left.end()));
        }
        if(!right.empty()){
            result = max(result,n - *min_element(right.begin(), right.end()));
        }
        return result;
    }
};
int main(){
    int n = 4;
    vector<int> left = {2};
    vector<int> right = {0, 1, 3};
    Solution ob;
    cout << ob.getLastMoment(n, left, right) << endl;
    return 0;
}