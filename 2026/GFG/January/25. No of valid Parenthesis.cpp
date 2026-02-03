#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findWays(int n) {
        // code here
        if(n%2 != 0) return 0;
        int k = n/2;
        long long c = 1;

        for(int i = 1; i <= k; i++){
            c = c * (4LL * i - 2) / (i + 1);//long long
        }
        return c;
    }
};
/*
class Solution {
  public:
    int findWays(int n) {
        // code here
        if(n%2 != 0) return 0;
        int k = n/2;
        long long c = 1;
        
        for(int i = 0; i < k; i++){
            c = c*(4LL*i - 2)/(i+1);
        }
        return c;
    }
};
*/
int main(){
    int n = 6;
    Solution s;
    cout<<s.findWays(n);
    return 0;
}