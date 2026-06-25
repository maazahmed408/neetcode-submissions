class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string,vector<string>> hashmap;

        for(string word : strs){
            string orgStr = word;
            sort(word.begin(),word.end());
            hashmap[word].push_back(orgStr);
        }

        for(auto& [sWord, group] : hashmap){  
            result.push_back(group);
         }

         return result;
    }
};
