class Solution {
public:
    int countSubstrings(string s) {
         if(s.size() <= 1) return s.size();

        int output = 0;

        for(int i = 0 ; i <s.size(); ++i){
            int l = i;
            int r = i;

            while(l >= 0 && r<s.size() && s[l] == s[r]){
                output++;
                --l;
                ++r;
            }
        }

        for(int i = 0 ; i <s.size(); ++i){
            int l = i;
            int r = i+1;

            while(l >= 0 && r<s.size() && s[l] == s[r]){
               output++;
                --l;
                ++r;
            }
        }

        return output;
    }
};
