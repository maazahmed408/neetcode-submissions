class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int,int> s_seen;
        unordered_map<int,int> t_seen;

        if(s.size() != t.size()) return false;

        for(int i = 0 ; i < s.size(); ++i){
            s_seen[s[i]]++;
            t_seen[t[i]]++;
        }

        return s_seen == t_seen;
    }
};
