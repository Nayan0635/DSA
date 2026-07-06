/*
Heap playilst video no 10
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    typedef pair<int, pair<int, int>> p;
    public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int> nums2, int k){
        priority_queue<p, vector<p>> pq;

        int m = nums1.size();
        int n = nums2.size();

        for (int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int sum = nums1[i] + nums2[j];

                if(pq.size() < k){
                    pq.push({sum, {i,j}});
                }else if(pq.top().first > sum){
                    pq.pop();
                    pq.push({sum, {i,j}});
                }
            }
        }


        vector<vector<int>> ans;

        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();

            int i = temp.second.first;
            int j = temp.second.second;

            ans.push_back({nums1[i], nums2[j]});
        }

        return ans;
    }
};
int main(){
    vector<int> arr1 = {1, 1, 2};
    vector<int> arr2 = {1, 2, 3};
    int k = 4;

    Solution s;
    vector<vector<int>> result = s.kSmallestPairs(arr1, arr2, k);

    for (auto& pair : result){
        for (auto& ind : pair){
            cout<<ind<<" ";
        }cout<<endl;
    }

    return 0;
}