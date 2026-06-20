class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> oneSeen;
        unordered_map<char,int> twoSeen;

        if(s.size() != t.size()){
            return false;
        }

        for(int i = 0 ; i < s.size();++i){
            oneSeen[s[i]]++;
            twoSeen[t[i]]++;
        }

        if(oneSeen == twoSeen){
            return true;
        }

        return false;

    }
};
