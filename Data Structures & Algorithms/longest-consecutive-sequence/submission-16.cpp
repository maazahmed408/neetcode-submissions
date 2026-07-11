class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hashset;
        for(int num : nums){
            hashset.insert(num);
        }
        int maxSize = 0;
        

        for(int i = 0; i < nums.size() ; ++i){
            int size = 0;
            if(hashset.find(nums[i] - 1) == hashset.end()){
                size++;
                int j = nums[i];
                while(hashset.find(j + 1) != hashset.end()){
                    size++;
                    ++j;
                }
                    maxSize = max(size, maxSize);
            }

        }

        return maxSize;

    }
};


        // 2 -> 1
        // 20-> 1
        // 4-> 1