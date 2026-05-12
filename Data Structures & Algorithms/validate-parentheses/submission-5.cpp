class Solution {
public:
    bool isValid(string s) {
        unordered_map<char , char> charMap = {
            {')','('},
            {'}','{'},
            {']','['}
        };

        stack<char> st;

        for(char c : s){

            if( c == '}' || c == ')' || c == ']'){
                if(!st.empty() && st.top() == charMap[c]){
                    st.pop();
                }else{
                    return false;
                }
            }
            else{
                st.push(c);
            } 
        }
    return st.empty();
    
    }
};
