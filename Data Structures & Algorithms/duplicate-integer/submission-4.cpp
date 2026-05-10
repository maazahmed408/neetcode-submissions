class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
    unordered_map<int , int> hashmap ;

    for(int i = 0; i < nums.size(); ++i){
        hashmap[nums[i]] += 1;
        if(hashmap[nums[i]] > 1){
            return true;
        }
    }
    return false;
    }
};