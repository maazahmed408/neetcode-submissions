class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        string res = "";
        
        for(int i = 0; i < strs[0].size();++i){
            for(string c : strs){
                if(!c[i] || c[i] != strs[0][i]) return res;

            }
                res+= strs[0][i];
        }

        return res;
    }
};