class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string,vector<string>> res;

        for(const auto& word : strs){
            vector<int> count(26,0);
            for(char c : word){
                count[c-'a']++;
            }
            string key = to_string(count[0]);
            for(int i = 1; i < 26; ++i){
                key += ',' + to_string(count[i]);
            }
            res[key].push_back(word);

        }

        for(auto& [sWord, group] : res){  
            result.push_back(group);
         }

         return result;
    }
};
