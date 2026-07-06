#include<bits/stdc++.h>
using namespace std;

int t[2001][2001][2];


/*
t[2001][2001][2] ..2001*2001*1 ~ 8Million * 4 bytes ~ 32MB if it's inside class S
since t is memeber variable, the entire 32MB object is created on the stack 
when you write Solution s;
system usually have 8MB stack space sometimes 1MB in windows
when you define outside class then it becomws tiny and won't overflow stack
*/



class Solution {
    public:
    //static int t[2001][2001][2]; or make it statc/global
    //vector<vector<vector<int>>> t; or allocate dynamically
    typedef long long ll;
    int MOD = 1e9 + 7;
    int N, M;

    int solve(int i, int prevVal, bool increasing) {

        if(i == N) {
            return 1;
        }

        if(t[i][prevVal][increasing] != -1) {
            return t[i][prevVal][increasing];
        }

        int result = 0;

        if(increasing) {
            for(int nextVal = prevVal + 1; nextVal <= M; nextVal++) {
                result = (result + solve(i + 1, nextVal, false)) % MOD;
            }
        }
        else {
            for(int nextVal = 1; nextVal < prevVal; nextVal++) {
                result = (result + solve(i + 1, nextVal, true)) % MOD;
            }
        }

        return t[i][prevVal][increasing] = result;
    }

    int zigZagArrays(int n, int l, int r) {

        N = n;
        M = r - l + 1;

        memset(t, -1, sizeof(t));

        ll result = 0;

        for(int startVal = 1; startVal <= M; startVal++) {

            // a < b > c < d...
            result = (result + solve(1, startVal, true)) % MOD;

            // a > b < c > d...
            result = (result + solve(1, startVal, false)) % MOD;
        }

        return result;
    }
};

int main() {

    int l = 4;
    int r = 5;
    int n = 3;

    Solution s;

    cout << s.zigZagArrays(n, l, r) << endl;

    return 0;
}