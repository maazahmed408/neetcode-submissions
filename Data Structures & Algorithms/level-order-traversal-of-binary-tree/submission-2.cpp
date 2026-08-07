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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> levelOrder;
        if(!root) return levelOrder;
        q.push(root);

        while(!q.empty()){
            int qlen = q.size();
            vector<int> level;
            for(int i = 0 ; i < qlen ; ++i){
                TreeNode* toPop = q.front();
                q.pop();
                level.push_back(toPop->val);
                if(toPop->left) q.push(toPop->left);
                if(toPop->right) q.push(toPop->right);
            }
            if(!level.empty()) levelOrder.push_back(level);
        }
        return levelOrder;
    }
};
