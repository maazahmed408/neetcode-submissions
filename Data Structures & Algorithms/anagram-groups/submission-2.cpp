class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string , vector<string>> stringMap;

        for(int i = 0; i < strs.size() ; ++i){

            vector<int> count(26,0);
            string key = "";
            for(auto& c : strs[i]){
                count[c - 'a']++;
            }
            for(int c = 0; c < 26 ; ++c){
                if(count[c] > 0){
                    key += to_string(count[c]) + char('a' + c) + "#";
                }
            }

            stringMap[key].push_back(strs[i]);

        }

        vector<vector<string>> output;

        for(const auto& i : stringMap){
            output.push_back(i.second);
        }

        return output;
    }
};
