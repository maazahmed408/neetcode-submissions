class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hashset;
        for(int num : nums){
            hashset.insert(num);
        }

        unordered_map<int,vector<int>> result;
        int maxSize = 0;

        for(int i = 0; i < nums.size() ; ++i){
            if(hashset.find(nums[i] - 1) == hashset.end() && result.find(nums[i]) == result.end()){
                result[nums[i]].push_back(nums[i]);
                int j = nums[i];
                while(hashset.find(j + 1) != hashset.end()){
                    result[nums[i]].push_back(j + 1);
                    ++j;
                }
                    maxSize = max((int)result[nums[i]].size() , maxSize);
            }

        }

        return maxSize;

    }
};


        // 2 -> 1
        // 20-> 1
        // 4-> 1