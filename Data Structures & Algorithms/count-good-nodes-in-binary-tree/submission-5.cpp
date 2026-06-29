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
        if (!root) return 0;

        int count = 0;
        maxdfs(root , count,root->val);
        return count;
    }

    void maxdfs(TreeNode* root, int& count ,int maxVal){
        if(!root){
            return ;
        }

        if(root->val >= maxVal){
            maxVal = root->val;
            ++count;
        }

        maxdfs(root->left,count,maxVal);
        maxdfs(root->right,count,maxVal);

        return ;

    }
};
