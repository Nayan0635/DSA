#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int josephus(int n, int k){
        int ans = 0;
        for(int i = 1; i <= n; i++){
            ans = (ans+k) % i;
        }
        return ans+1;
    }
};

int main(){
    int n = 5, k = 2;
    Solution s;
    cout<<s.josephus(n, k);
    return 0;
}