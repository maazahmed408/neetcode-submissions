class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if ( s.size() <= 0 ) return 0;
        int len = INT_MIN;
        unordered_set<char> charSet;
        int l = 0;
        int r = 0;

        while(r<s.size()){
            while(charSet.count(s[r])){
               charSet.erase(s[l]);
                ++l;
            }
            charSet.insert(s[r]);
            len = max(len , r-l+1);
            ++r;
        }

        return len;
    }
};
