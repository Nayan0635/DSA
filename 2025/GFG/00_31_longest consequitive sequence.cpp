//longest consequitive sequence
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int longestConsequitive(vector<int> & arr){//Optimal
        int n = arr.size();
        if(n == 0) return 0;
        int longest = 1;
        unordered_set<int> st;
        for (int i = 0; i < n; i++){//-------->O(N)
            st.insert(arr[i]);//insert the elements
        }
        for (auto i: st){
            if (st.find(i - 1) == st.end()){/*if previous one isn't presant
            you are part of my sequence*/
                int cnt = 1;
                int x = i;//you are my first element
                while (st.find(x+1) != st.end()){
                    x = x + 1;
                    cnt++;
                }
                longest = max(longest, cnt);
            }
        } 
        return longest;
    }
};
int main(){
    
    Solution s;
    return 0;
}//31/12/24
