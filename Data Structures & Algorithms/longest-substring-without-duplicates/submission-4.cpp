class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int l = 0;
        int maxSize = 0;
        unordered_set<char> hashset;
        for(int r = 0 ; r < s.size(); ++r){
            while(!hashset.empty() && hashset.count(s[r])){
                hashset.erase(s[l]);
                ++l;
            }
            hashset.insert(s[r]);
            maxSize = max(maxSize, r-l+1);
        }
        return maxSize;
    }
};
