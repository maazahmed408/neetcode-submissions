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
    int goodNodes(TreeNode* root) {
        if(!root) return 0;

        int maxVal = root->val;
        int count = 0;

        dfs(root,maxVal,count);
        return count;
    }

    void dfs(TreeNode* root, int maxVal, int& count){
        if(!root) return;

        if(maxVal <= root->val){
            maxVal = root->val;
            ++count;
        }

        dfs(root->left,maxVal,count);
        dfs(root->right,maxVal,count);
    }
};
