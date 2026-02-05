/*
nums1 = [4, 1, 2] nums2 = [1, 3, 4, 2]
output = [-1, 3, 1]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2){
        int n2 = nums2.size();
        vector<int> nge2(n2, -1);
        int n1 = nums1.size();
        vector<int> nge1(n1);       
        unordered_map<int, int> mp; 
        stack<int> st;

        for(int i = n2-1; i >= 0; i--){
            while(!st.empty() && st.top() <= nums2[i])//smaller element
                st.pop();//take it out
            if(st.empty()) nge2[i] = -1;//no greater elements
            else nge2[i] = st.top();// top is my nge2
            st.push(nums2[i]);//push curr element for future work
            //--> nge2 ready for nums2
        }
        for(int i = n2-1; i >= 0; i--){
            mp[nums2[i]] = nge2[i];
        }
        for(int i = n1-1; i >= 0; i--){
            nge1[i] = mp[nums1[i]];
        }
        return nge1;
    }
};
int main(){
    vector<int> arr1 = {4, 1, 2};
    vector<int> arr2 = {1, 3, 4, 2};
    Solution s;
    vector<int> ans = s.nextGreaterElement(arr1, arr2);
    for (auto& it : ans){
       cout<<it<<" ";
    }
    return 0;
}