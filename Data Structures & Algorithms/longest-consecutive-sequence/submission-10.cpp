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

        unordered_map<int , vector<int> > hashmap;
        int maxSize = 1;
        for(int i : nums){
            int c = i;
            int size = 1;
                while( hashset.count(c+1)){
                hashmap[i].push_back(c);
                ++size;
                maxSize = max(maxSize, size);
                ++c;
            }    
        }

        return maxSize;

    }
};
