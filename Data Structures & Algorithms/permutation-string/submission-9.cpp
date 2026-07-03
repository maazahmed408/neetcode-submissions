class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> count_s1(26,0);
        vector<int> count_s2(26,0);
        int matches = 0;

        if (s1.size() > s2.size()) return false;

        for(int i = 0 ; i < s1.size();++i){
            count_s1[s1[i]-'a']++;
            count_s2[s2[i]-'a']++;
        }

        for(int i = 0; i < 26 ; ++i){
            if(count_s1[i] == count_s2[i]){
                matches++;
            }
        }

        int l = 0;

        for(int r = s1.size() ; r <s2.size();++r){
            if(matches == 26){
                return true;
            }
            int toAdd = s2[r] - 'a';
            int toRemove = s2[l] - 'a';

            count_s2[toAdd]++;
            if(count_s1[toAdd] == count_s2[toAdd]) matches++;
            else if(count_s1[toAdd] == count_s2[toAdd] - 1) matches--;

            count_s2[toRemove]--;
            if(count_s1[toRemove] == count_s2[toRemove]) matches++;
            else if(count_s1[toRemove] == count_s2[toRemove] + 1) matches--;
            
            ++l;
        }

        if(matches == 26){
            return true;
        }

        return false;

    }
};
