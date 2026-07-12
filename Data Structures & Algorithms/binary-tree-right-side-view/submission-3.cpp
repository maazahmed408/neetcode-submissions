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
      queue<TreeNode*> q;
        vector<int> result;
        q.push(root);

        while(!q.empty()){
            int last;
            int len = q.size();
            while(len > 0){
                TreeNode* node = q.front();
                q.pop();
                if(node){
                // level.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                if(len == 1) result.push_back(node->val);
                }
                --len;
            }
        }

        return result;

    }

    void dfs(TreeNode* root, int level , vector<int>& res){
        if(!root) return ;

        if(res.size() == level){
            res.push_back(root->val);
        }

        dfs(root->right,level + 1, res);
        dfs(root->left,level + 1, res);


    }
};
