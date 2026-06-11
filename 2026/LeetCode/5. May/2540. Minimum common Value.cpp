#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int getCommon(vector<int>& nums1, vector<int>& nums2){ //two pointer
    }


    /*3. two ppointers update simultaneously to get minimum*/
    int getCommon(vector<int>& nums1, vector<int>& nums2){ //two pointer
        
        int i = 0;
        int j = 0;
        int n = nums1.size(), m = nums2.size();
        int result = -1;
        while(i < n && j < m){
            if(nums1[i] < nums2[j]){
                i++;
            }else if(nums2[j] < nums1[i]){
                j++;
            }else{
                result = nums1[i];
                break;
            }
        }

        return result;
    }
};
int main(){
    vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> arr2 = {2, 4, 6, 7};
    Solution s;
    cout<<s.getCommon(arr1, arr2);
    return 0;
}