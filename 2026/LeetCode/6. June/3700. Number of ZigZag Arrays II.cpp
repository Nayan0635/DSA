#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef long long ll;
    int MOD = 1e9+7;
    int N, M;

    int t[2001][2001][2];

    int solve(int i, int prevVal, bool increasing) {
        if(i == N) { //able to find N elements of zigzag array
            return 1;
        }

        if(t[i][prevVal][increasing] != -1) {
            return t[i][prevVal][increasing];
        }

        int result = 0;
        if(increasing) {
            for(int nextVal = prevVal+1; nextVal <= M; nextVal++) {
                result = (result + solve(i+1, nextVal, false)) % MOD;
            }
        } else {
            for(int nextVal = 1; nextVal < prevVal; nextVal++) {
                result = (result + solve(i+1, nextVal, true)) % MOD;
            }
        }

        return t[i][prevVal][increasing] = result;
    }

    int zigZagArrays(int n, int l, int r) {
        N = n;
        M = r-l+1;
        memset(t, -1, sizeof(t));

        ll result = 0;

        for(int startVal = 1; startVal <= M; startVal++) {
            //a < b > c < d ...
            result = (result + solve(1, startVal, true)) % MOD;

            //a > b < c > d...
            result = (result + solve(1, startVal, false)) % MOD;
        }

        return result;
    }
};


int main(){
    int l, r, n;
    l = 4, r = 5, n = 3;
    Solution s;
    cout << s.zigZagArrays(n, l, r);
    return 0;
}