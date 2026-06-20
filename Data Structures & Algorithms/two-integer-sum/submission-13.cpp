class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int,int> hashset;

      for(int i = 0 ; i < nums.size() ; ++i){
        int diff = target - nums[i];
        if(hashset.find(diff) != hashset.end()){
            return {hashset[diff],i};
        }
        hashset.insert({nums[i],i});
      }  

      return {-1 , -1};
    }
};
