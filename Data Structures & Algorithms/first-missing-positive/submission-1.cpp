class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        unordered_set<int> hashset(nums.begin(),nums.end());
        

       for(int i = 1 ; i <= nums.size() + 1; ++i){
        if(!hashset.count(i)) return i;
       }

       return -1;
    }
};