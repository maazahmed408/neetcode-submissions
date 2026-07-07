class Solution {
    vector<int> dp;
public:
    int rob(vector<int>& nums) {
        dp.resize(nums.size(),-1);
        int house = nums.size()-1;
        return dfs(house,nums);
    }

    int dfs(int house , vector<int>& nums){
        if(house < 0 ) return 0;
        if(dp[house] != -1) return dp[house];

        int skip = dfs(house-1,nums);
        int take = nums[house] + dfs(house-2,nums);

        return dp[house] =  max(skip,take);
    }
};