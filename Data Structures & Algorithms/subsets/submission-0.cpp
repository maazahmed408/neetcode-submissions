class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ds ;
        findSubsets(0,ds,nums);
        return res;
    }

    void findSubsets(int i , vector<int> ds , vector<int>& nums){
        if(i == nums.size()){
            res.push_back(ds);
            return;
        }
        // pickelement
        ds.push_back(nums[i]);
        findSubsets(i+1,ds,nums);
        ds.pop_back();
        findSubsets(i+1,ds,nums);
    }
};
