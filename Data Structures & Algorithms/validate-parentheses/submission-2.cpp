class Solution {
public:
    bool isValid(string s) {
   unordered_map<char ,char> paraMap;
   stack<char> st;

   paraMap = {
    {')','('},
    {'}','{'},
    {']','['},
   };

    for(auto& c : s){
        if(c =='(' || c == '[' || c== '{'){
            st.push(c);
        }else{
            if(!st.empty() && st.top() == paraMap[c]){
                st.pop();
            }else{
                return false;
            }
        }
    }
    
    return st.empty();

    }
};
