/*
height[j] < height[i],
There is no person k standing between them such that height[k] ≥ height[i].

Each person can see in both directions (front and back).
Your task is to find the maximum number of people that any person can see (including themselves).

Constraints:
1 ≤ arr.size() ≤ 10^4
1 ≤ arr[i] ≤ 10^5
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int maxPeople(vector<int> &arr) {
        // code here
        int n = arr.size();
        stack<int> st;
        vector<int> nextGE(n, n);
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] < arr[i]) st.pop();
            if(!st.empty()) nextGE[i] = st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        
        vector<int> prevGE(n, -1);
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] < arr[i]) st.pop();
            if(!st.empty()) prevGE[i] = st.top();
            st.push(i);
        }
        
        int maxVisible = 0;
        for(int i = 0; i < n; i++){
            int left_count = (prevGE[i] == -1) ? i : i - prevGE[i] - 1;
            int right_count = nextGE[i] - i - 1;
            maxVisible = max(maxVisible, left_count + right_count + 1);
        }
        
        return maxVisible;
    }
};

int main(){
    vector<int> arr = {6, 2, 5, 4, 5, 1, 6 };
    Solution s;
    int ans = s.maxPeople(arr);
    cout<<ans;
    return 0;
}