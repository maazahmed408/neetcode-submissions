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
    int goodNode = 0;
public:
    int goodNodes(TreeNode* root) {

        countNode(root,INT_MIN);

        return goodNode;
        
    }
    void countNode(TreeNode* root,int greaterNode){
        if(!root) return ;

        if(root->val >= greaterNode) {
            greaterNode = max(greaterNode,root->val);
            goodNode++;
        }

        countNode(root->left,greaterNode);
        countNode(root->right,greaterNode);

        return;
    }
};
