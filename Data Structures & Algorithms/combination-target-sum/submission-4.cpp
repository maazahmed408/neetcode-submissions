class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> ds;
        dfs(0,target,ds,nums,res);
        return res;
    }

    void dfs(int i, int target,vector<int> ds,vector<int>& nums,vector<vector<int>>& res){
     if(target == 0){
        res.push_back(ds);
        return;
     }

     if(target < 0 || i >= nums.size()) return;

     ds.push_back(nums[i]);
     dfs(i, target-nums[i],ds,nums,res);

     ds.pop_back();
     dfs(i+1, target,ds,nums,res);


    }
};
