class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> hashset;
        int maxLen = 0;
        int l = 0 ;

        for(int r = 0 ; r < s.size(); ++r){
            while(hashset.count(s[r])){
                hashset.erase(s[l]);
                ++l;
            }
            hashset.insert(s[r]);
            maxLen = max(maxLen , r-l+1);
        }
        return maxLen;
    }
};
