class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.size()==1){
            return 1;
        }
        unordered_set<int> hashset(nums.begin(),nums.end());
        int best = 0 ;

       for(int n : hashset){
        if(hashset.find(n-1) == hashset.end()){
            int curr = n;
            int len = 1;

            while(hashset.find(curr+1) != hashset.end()){
                curr++;
                len++;


            }
                best = max(best,len);
        }
       }

        return best;
    }
};
