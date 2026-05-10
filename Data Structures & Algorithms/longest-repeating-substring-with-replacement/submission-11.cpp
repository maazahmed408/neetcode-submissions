class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxF = 0;
        unordered_map<char,int> charMap;
        int maxLen = -1;

        int l = 0;
        for(int r = 0; r<s.size();++r){
            char toAdd = s[r];
            char toRemove = s[l];
            charMap[toAdd]++;
            maxF = max(charMap[toAdd],maxF);
            if((r-l+1) - maxF  > k){
                charMap[toRemove]--;
                ++l;
            }
            maxLen = max(maxLen,r-l+1);

        }

        return maxLen;
    }
};
