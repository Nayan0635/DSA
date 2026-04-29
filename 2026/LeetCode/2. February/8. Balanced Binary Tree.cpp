#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return dfsHeight(root) != -1;
    }

    int dfsHeight(TreeNode* root){
        if(root == nullptr) return 0;
        int leftHeight = dfsHeight(root->left);
        int rightHeight = dfsHeight(root->right);

        //if any is unbalaced no need to check anything
        if(leftHeight == -1) return -1;
        if(rightHeight == -1) return -1;

        if(abs(leftHeight-rightHeight) > 1) return -1;

        return max(leftHeight, rightHeight) + 1;
    }
};