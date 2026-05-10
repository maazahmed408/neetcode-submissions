class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.empty()){
            return 0;
        }

        unordered_set<int> hashset;

        for(int m : nums){
            hashset.insert(m);
        }

        int maxSize = 1;
        for(int i : nums){
            int c = i;
            int size = 1;
                while(!hashset.count(i-1) && hashset.count(c+1)){
                ++size;
                maxSize = max(maxSize, size);
                ++c;
            }    
        }

        return maxSize;

    }
};
