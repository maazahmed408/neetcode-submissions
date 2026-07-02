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
    int kthSmallest(TreeNode* root, int k) {
        int res = 0;
        dfs(root,res,k);
        return res;
    }

    void dfs(TreeNode* root,int& res,int& k){
        if(!root) return ;

        dfs(root->left,res,k);

        if(k==0) return ;
        --k;
        if(k == 0){
            res = root->val;
        }
        
        dfs(root->right,res,k);
    }

};
