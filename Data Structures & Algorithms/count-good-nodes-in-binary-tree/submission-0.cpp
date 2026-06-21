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
        if(!root){
            return 0;
        }

        int count = 0;
        int maxNumber = root->val;

        maxDfs(root,maxNumber,count);

        return count;

    }

    void maxDfs(TreeNode* root , int maxNumber,int &count){
        if(!root){
            return ;
        }
        if(root->val >= maxNumber){
            maxNumber = root->val;
            count++;
        }

        maxDfs(root->left,maxNumber,count);
        maxDfs(root->right,maxNumber,count);

        return ;

    }
};
