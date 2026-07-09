class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0,{},nums);
        return res;
    }

    void dfs(int i , vector<int> ds, vector<int>& nums){
        if(i >= nums.size()){
            res.push_back(ds);
            return ;
        }

        ds.push_back(nums[i]);
        dfs(i+1,ds,nums);

        ds.pop_back();
        dfs(i+1,ds,nums);
        
    }
};
