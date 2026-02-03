// print matrix spirally
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> spirallyTraverse(vector<vector<int>> &mat){
        if (mat.empty())
            return {};
        int n = mat.size();    // column size
        int m = mat[0].size(); // row size
        int left = 0, right = m - 1;
        int top = 0, bottom = n - 1;
        vector<int> ans;
        while (left <= right && top <= bottom){
            for (int i = left; i <= right; i++){ // right
                ans.push_back(mat[top][i]);
            }
            top++;
            for (int i = top; i <= bottom; i++){ // down
                ans.push_back(mat[i][right]);
            }
            right--;
            if (left <= right)
            {
                for (int i = right; i >= left; i--){ // left
                    ans.push_back(mat[bottom][i]);
                }
            }
            bottom--;
            if (top <= bottom){
                for (int i = bottom; i >= top; i--){ // up
                    ans.push_back(mat[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};
int main(){
    vector<vector<int>> vec = {{1, 2, 3, 4, 5}};
    Solution s;
    s.spirallyTraverse(vec);
    for(auto& row : vec){
        for(int i : row) cout<<i<<" ";
    }
    
    return 0;
}//21/12/24