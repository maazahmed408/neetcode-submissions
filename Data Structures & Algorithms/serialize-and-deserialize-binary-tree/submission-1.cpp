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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        dfs(root,res);
        return res;

    }

    void dfs(TreeNode* root, string& res){
        if(!root){
            res+= 'N';
            res+= ',';
            return ;
        }

        res += to_string(root->val) + ',';

        dfs(root->left,res);
        dfs(root->right,res);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> values = split(data);
        int i = 0;
        return buildTree(values,i);
    }

    TreeNode* buildTree( vector<string>& values,int& i){
        if(values[i] == "N"){
            ++i;
            return nullptr;
        }

        TreeNode* node = new TreeNode(stoi(values[i]));
        ++i;

        TreeNode* left = buildTree(values,i);
        TreeNode* right = buildTree(values,i);

        node->left = left;
        node->right = right;

        return node;
        
    }


    vector<string> split(string data){
        vector<string> res;
        string curr = "";
        for(char c : data){
            if(c == ','){
                res.push_back(curr);
                curr="";
            }else{
                curr += c;
            }
        }
        return res;
    }
};
