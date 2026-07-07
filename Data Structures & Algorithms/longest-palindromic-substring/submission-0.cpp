class Solution {
public:
    string longestPalindrome(string s) {
        //start from each index then loop their left and right check if palindrome or not;

        if(s.size() <= 1) return s;

        int maxLen = 0;
        pair<int,int> longString;
        string output = "";

        for(int i = 0 ; i <s.size(); ++i){
            int l = i;
            int r = i;

            while(l >= 0 && r<s.size() && s[l] == s[r]){
                if(maxLen < r-l+1){
                    longString = {l,r};
                    maxLen = r-l+1;
                }
                --l;
                ++r;
            }
        }

        for(int i = 0 ; i <s.size(); ++i){
            int l = i;
            int r = i+1;

            while(l >= 0 && r<s.size() && s[l] == s[r]){
                if(maxLen < r-l+1){
                    longString = {l,r};
                    maxLen = r-l+1;
                }
                --l;
                ++r;
            }
        }
        for(int l = longString.first ; l <= longString.second ; ++l){
            output += s[l];
        }

        return output;
    }
};
