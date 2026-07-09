class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string ds;
        dfs(0,0,ds,res,n);
        return res;
    }

    void dfs(int open, int close, string ds,vector<string>& res,int& n){
     if(open == n && close == n){
        res.push_back(ds);
     }
     if(open < n){
        ds += '(';
        dfs(open+1,close,ds,res,n);
        ds.pop_back();
     }

     if(close < open){
        ds += ')';
        dfs(open,close+1,ds,res,n);
        ds.pop_back();
     }

    }


};
