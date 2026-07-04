class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        vector<string> ds;
        dfs(0,0,ds,res,n);
        return res;
    }

    void dfs(int open, int close, vector<string> ds,vector<string>& res,int& n){
        if(open == close && open == n){
            res.push_back(join(ds));
            return;
        }

        if(open < n){
            ds.push_back("(");
            dfs(open+1,close,ds,res,n);
            ds.pop_back();
        }

        if(close < open){
            ds.push_back(")");
            dfs(open,close+1,ds,res,n);
            ds.pop_back();
        }
    }

    string join(vector<string> data){
        string res = "";
        for(string ch : data){
            res += ch;
        }
        return res;
    }
};
