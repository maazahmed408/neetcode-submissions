class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, vector<int>> seq;
        unordered_set<int> hashset(nums.begin(),nums.end());
        int maxSeq = 0;
        int count = 0;
        for(int i : hashset){
            if(hashset.find(i-1) == hashset.end()){
                int r = i;
                while(hashset.find(r) != hashset.end()){
                    seq[r].push_back(r);
                    ++count;
                    maxSeq = max(maxSeq,count);
                    ++r;
                }
                count = 0;
            }
        }

        return maxSeq;

    }
};
