class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> count_s;
        unordered_map<char,int> count_t;
        for(char& c : t){
            count_t[c]++;
        }

        int have = 0;
        int need = count_t.size();

        int minLen = INT_MAX;
        string minString = "";

        int l = 0;
        for(int r = 0; r<s.size(); r++){
            count_s[s[r]]++;
            if(count_s[s[r]] == count_t[s[r]]) have++;

            while(have == need){
                if(minLen > r-l+1){
                    minString = s.substr(l,r-l+1);
                    minLen = r-l+1;
                }

                count_s[s[l]]--;
                if(count_s[s[l]] < count_t[s[l]]) have--;
                ++l;
            }

        }

        return minString;
    }
};
