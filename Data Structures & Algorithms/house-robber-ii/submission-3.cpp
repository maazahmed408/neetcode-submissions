class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0],nums[1]);

        int prev2 = nums[0]; // house - 2; take 
        int prev1 = max(nums[0],nums[1]); //house - 1; skip


        for(int i = 2; i <nums.size()-1; ++i){
            int curr = max(prev1,nums[i] + prev2);
            prev2 = prev1;
            prev1 = curr;
        }

        prev2 = nums[1];
        int prev3 = max(nums[1],nums[2]);

        for(int i = 3; i <nums.size(); ++i){
         int curr = max(prev3, nums[i] + prev2);
            prev2 = prev3;
            prev3 = curr;
        }

        return max(prev1,prev3);




    }
};
//curr = max(prev1 , nums[i] + prev2)