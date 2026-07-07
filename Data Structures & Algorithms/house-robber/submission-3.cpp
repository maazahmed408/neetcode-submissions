class Solution {
    vector<int> dp;
public:
    int rob(vector<int>& nums) {
        dp.resize(nums.size(),-1);
        // int house = nums.size()-1;
        // return dfs(house,nums);
        if (nums.size() == 1) return nums[0];

        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);

        for(int i = 2 ; i < nums.size();++i){
            dp[i] = max(dp[i-1],nums[i] + dp[i-2]);
        }

        return dp[nums.size()-1];
    }

    int dfs(int house , vector<int>& nums){
        if(house < 0 ) return 0;
        if(dp[house] != -1) return dp[house];

        int skip = dfs(house-1,nums);
        int take = nums[house] + dfs(house-2,nums);

        return dp[house] =  max(skip,take);
    }
};