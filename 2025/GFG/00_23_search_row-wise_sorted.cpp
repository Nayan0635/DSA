//search in a Row-wise sorted matrix
#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    bool bs(vector<int> &arr, int k){//binary search O(logN)
        int low = 0, high = arr.size() - 1;
        while (low <= high){
            int mid = low + (high - low)/2;
            if (arr[mid] == k)  return true;
            if (arr[mid] < k)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;    
    }
    bool searchRowMatrix(vector<vector<int>> &mat, int target){
        int n = mat.size();//no of rows
        int m = mat[0].size();//no of columns

        for (int i = 0; i < n; i++){
            //check if the target can be presant or not
            if (mat[i][0] <= target && target <= mat[i][m-1]){
                //now start searching
                if (bs(mat[i], target)) return true;
            }
        }//after searching everywhere
        return false;//say not presant
    }
};
int main(){
    vector<vector<int>> arr = {{3, 4, 9},{2, 5, 6},{9, 25, 27}};
    Solution s;
    cout<<s.searchRowMatrix(arr, 5);
    return 0;
}//23/12/24