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
    unordered_map<int,int> inorderMap;
    int preIdx = 0;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //preorder = node->left->right
        //inorder = left->node->right;

        for(int i = 0 ; i < inorder.size(); ++i){
            inorderMap[inorder[i]] = i;
        }

        return buildBinaryTree(preorder,0,preorder.size()-1);

    }

    TreeNode* buildBinaryTree(vector<int>& preorder, int l , int r){

        if(l>r) return nullptr;

        int rootVal = preorder[preIdx++];

        int mid = inorderMap[rootVal];

        TreeNode* node = new TreeNode(rootVal);

        node->left = buildBinaryTree(preorder,l,mid-1);
        node->right = buildBinaryTree(preorder,mid+1,r);

        return node;
    }
};
