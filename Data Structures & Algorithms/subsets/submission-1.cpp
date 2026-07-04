class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ds;
        dfs(0,ds,res,nums);
        return res;
    }

    void dfs(int i , vector<int> ds, vector<vector<int>>& res, vector<int>& nums ){
        if(i>=nums.size()){
            res.push_back(ds);
            return;
        }

        ds.push_back(nums[i]);
        dfs(i+1,ds,res,nums);
        ds.pop_back();
        dfs(i+1,ds,res,nums);
    }
};
