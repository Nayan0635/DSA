//return the final array by repeatedly applying
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> reducepairs(vector<int>& arr){
        vector<int> ans;
        stack<int> st;
        int n = arr.size();
        for(int i = 0; i < n; i++){
            //keep poping while arr[i] wins 
            while(!st.empty() && (st.top() ^ arr[i]) < 0 && abs(arr[i]) > abs(st.top())){
                st.pop();
            }
            if(!st.empty() && (st.top() ^ arr[i]) < 0){
                if(abs(st.top()) == abs(arr[i])){
                    st.pop(); // both die
                }
            }
            else{//same sign or survived
                st.push(arr[i]);
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
int main(){
    vector<int> arr = {5, -5, 2, -10};
    Solution s;
    vector<int> ans = s.reducepairs(arr);
    for (auto& it : ans){
        cout<<it<<" ";
    }
    return 0;
}