class Solution {
public:

    string encode(vector<string>& strs) {
        string encodedString = "";
        for(const string& s : strs){
            encodedString += to_string(s.size());
            encodedString += "#";
            encodedString.append(s);
        }

        return encodedString;
    }

    // [5#Hello5#world]

    vector<string> decode(string s) {
        vector<string> decoded;
        int i = 0;
        while(i<s.size()){
            int j = i;
            while(s[j] != '#'){
                ++j;
            }
            int len = stoi(s.substr(i,j-i));
            string extract = s.substr(j+1,len);
            decoded.push_back(extract);
            i = j+1+len;
        }

        return decoded;
    }
};
