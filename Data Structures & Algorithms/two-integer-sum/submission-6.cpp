class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int,int> hashset;
        hashset.insert({nums[0],0});
        for(int i = 1; i < nums.size() ; ++i){
           int diff = target - nums[i];
            auto it = hashset.find(diff);
           if(it == hashset.end()){
            hashset.insert({nums[i],i});
           }else{
            return {it->second,i};
           }
        }

        return {-1,-1};
    }
};
