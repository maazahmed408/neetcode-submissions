class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> stringMap;
        vector<vector<string>> output;
        for(string str : strs){
            vector<int> charMap(26,0);
            for(char ch : str){
                charMap[ch - 'a']++;
            }
            string key = "";
            for(int n = 0 ; n <  charMap.size() ; ++n){
                if(charMap[n] != 0){
                    key += to_string(charMap[n]);
                    key += 'a' + n ;
                    key += ',';
                }
            }

            stringMap[key].push_back(str);
        }
        
        for(auto& [key,strArr] : stringMap){
            output.push_back(strArr);
        }

        return output;
        
    }
};
