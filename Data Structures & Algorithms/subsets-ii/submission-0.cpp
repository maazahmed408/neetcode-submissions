class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        dfs(0,{},res,nums);
        return res;
    }

    void dfs(int i, vector<int> ds,vector<vector<int>>& res, vector<int>& nums){
       res.push_back(ds);

        for(int j = i; j<nums.size();++j){
            if(j > i && nums[j] == nums[j-1]) continue;
            ds.push_back(nums[j]);
            dfs(j+1,ds,res,nums);
            ds.pop_back();
        }



    }
};
