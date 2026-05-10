class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char , int> countT;
        unordered_map<char,int> window;

        for(int i = 0; i<t.size();++i){
            countT[t[i]]++;
        }

        int have = 0;
        int need = countT.size();
        pair<int, int> res (-1,-1);
        string output = "";
        int l = 0;
        int minLen = INT_MAX;

        if(t.size() > s.size()){
            return output;
        }

        for(int r = 0 ; r<s.size(); ++r){

            window[s[r]]++;
            if(countT.count(s[r]) && countT[s[r]] == window[s[r]]){
                have = have +1;
            }
            
            while(have == need){
                if(minLen > r-l+1){
                    minLen = r-l+1;
                    res.first = l;
                    res.second = r;
                }

                if(countT.count(s[l]) && window[s[l]] == countT[s[l]]){
                    have = have - 1;
                }
                    window[s[l]]--;
                    l++;
            }

        }
        if (res.first != -1) {
            for(int i = res.first; i <= res.second;++i){
                output += s[i];
            }
        }

        return output;
        
    }
};
