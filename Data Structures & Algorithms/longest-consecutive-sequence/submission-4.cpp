class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hashset;
        int streak = 0;

        for(int i : nums){
            hashset.insert(i);
        }

        for(auto num : hashset){

            if(hashset.find(num - 1) == hashset.end()){
               int len = 1;
               while(hashset.find(num + len) != hashset.end()){
                ++len;
               }
               streak = max(len,streak);
            }
        }

        return streak;

    }
};
