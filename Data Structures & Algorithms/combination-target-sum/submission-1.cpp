class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        dfs(0,{},0,nums,target);
        return res;
    }
private:
    void dfs(int i , vector<int> curr, int total,vector<int>& nums,int target){
        if (total == target){
            // auto copy = curr;
            res.push_back(curr);
            return;
        }
        if(i >= nums.size() || total > target){
            return ;
        }

        curr.push_back(nums[i]);
        dfs(i,curr,total+nums[i],nums,target);

        curr.pop_back();
        dfs(i+1,curr,total,nums,target);
    }
};
