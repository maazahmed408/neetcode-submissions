class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> num_set;

        for(int i : nums){
            if(num_set.count(i))
                return true;
            num_set.insert(i);
        }

        return false;
    }
};