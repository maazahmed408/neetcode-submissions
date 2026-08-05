class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string = "";
        for(string& str : strs){
            encoded_string += to_string(str.size());
            encoded_string += '#';
            encoded_string += str;
        }

        return encoded_string;
    }

    vector<string> decode(string s) {
        // 5#hello6#worlds
        vector<string> output;
        string str_size = "";
        int i = 0;
        while(i < s.size()){

            if(isdigit(s[i])){
                str_size += s[i];
                ++i;
            }
            else if(s[i] == '#'){
                int string_size = stoi(str_size);
                str_size = "";
                string new_string = "";
                int k = 1;
                while( k <= string_size){
                    new_string += s[i+k];
                    ++k;
                }
                output.push_back(new_string);
                i = k+i;
            }
        }

        return output;
    }
};
