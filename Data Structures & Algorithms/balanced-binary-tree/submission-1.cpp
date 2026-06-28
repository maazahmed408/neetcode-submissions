/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        bool isValid = true;
        dfs(root,isValid);

        return isValid;
    }

    int dfs(TreeNode* root,bool& isValid){
        if (root == nullptr){
            return 0;
        }

        int left = dfs(root->left,isValid);
        int right = dfs(root->right,isValid);

        if(abs(left - right) > 1){
            isValid = false;
            return 0;
        }

        return 1 + max(left,right);

    }
};
