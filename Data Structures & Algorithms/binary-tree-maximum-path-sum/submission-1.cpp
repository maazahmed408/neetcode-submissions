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
    int maxPathSum(TreeNode* root) {
        int maximum = INT_MIN;
        dfs(root,maximum);
        return maximum;
    }

    int dfs(TreeNode* root,int& maximum){
        if(!root){
            return 0;
        }

        int left = max(0,dfs(root->left,maximum));
        int right = max(0,dfs(root->right,maximum));

        maximum = max(root->val + left + right,maximum);

        return root->val + max(left,right);
    }

};
