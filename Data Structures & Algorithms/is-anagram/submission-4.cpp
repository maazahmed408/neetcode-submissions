class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char , int> hashmapS;
        unordered_map<char , int> hashmapT;
       if(s.size() != t.size()){
        return false;
       }
        for(int i = 0; i < s.size();++i){
            hashmapS[s[i]]++;
            hashmapT[t[i]]++;
        }

        return hashmapS == hashmapT;
    }
};
