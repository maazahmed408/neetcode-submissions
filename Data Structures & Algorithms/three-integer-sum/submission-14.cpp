class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> output;

        for(int i = 0 ; i < nums.size(); ++i){
            if(nums[i] > 0) break;
            if(i > 0 && nums[i] == nums[i-1]) continue;

            int l = i+1;
            int r = nums.size() - 1;

            while(l < r){
                int sum = nums[l] + nums[r] + nums[i];

                if(sum < 0) ++l;
                else if(sum > 0) --r;
                else{
                    output.push_back({nums[i],nums[l],nums[r]});
                    ++l;
                    while(l < nums.size() && nums[l] == nums[l-1]){
                        ++l;
                    }
                    --r;
                } 
            }
        }

        return output;
    }
};
