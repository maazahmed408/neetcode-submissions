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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot){
            return true;
        }
        if(!root && subRoot != nullptr){
            return false;
        }
        if(root != nullptr && !subRoot){
            return true;
        }

        if(root && subRoot){
           return isSameBT(root, subRoot)
                || isSubtree(root->left, subRoot)
                || isSubtree(root->right, subRoot);
        }
        
    }

    bool isSameBT(TreeNode* root, TreeNode* subRoot){
        if(!root && !subRoot) return true;

        if(root && subRoot && root->val == subRoot->val){
            return isSameBT(root->left,subRoot->left) && isSameBT(root->right, subRoot->right);
        }else{
            return false;
        }
    }
};
