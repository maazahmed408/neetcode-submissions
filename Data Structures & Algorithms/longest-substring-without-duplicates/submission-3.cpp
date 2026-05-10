class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;
        int maxLen = 0;
        int l = 0;
        for(int r = 0 ; r < s.size() ; ++r){

            while(charSet.count(s[r])){
                charSet.erase(s[l]);
                ++l;
            }

            charSet.insert(s[r]);
            maxLen = max(maxLen, r-l+1);
        }

        return maxLen;
    }
};
