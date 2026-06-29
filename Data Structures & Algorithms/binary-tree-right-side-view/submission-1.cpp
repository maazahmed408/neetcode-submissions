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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};

        queue<TreeNode*> q;
        q.push(root);
        vector<int> res;

        while(!q.empty()){
            int qlen = q.size();
            TreeNode* rightSide = nullptr;
            for(int i = qlen ; i>0;i--){
                TreeNode* toPop = q.front();
                q.pop();
                if(toPop){
                    rightSide = toPop;
                    q.push(toPop->left);
                    q.push(toPop->right);
                }  
            }
            if(rightSide){
            res.push_back(rightSide->val);
            }
        }
        return res;
    }
};
