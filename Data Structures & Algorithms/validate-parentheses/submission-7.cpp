class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char,char> hashmap{
            {'}','{'},
            {']','['},
            {')','('}
        };

        for(const char& ch : s){
            if(hashmap.find(ch) == hashmap.end() || st.empty()){
                st.push(ch);
            }else{
                if(st.top() == hashmap[ch]) st.pop();

                else return false;
            }
        }

        return st.empty();
    }
};
