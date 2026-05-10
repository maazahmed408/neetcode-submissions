class Solution {
public:
    bool isAnagram(string s, string t) {
       if(s.length() != t.length())
        return false;

       unordered_map<char , int> str_one ;
       unordered_map<char , int> str_two ;
       
       for(int i = 0; i < s.length(); ++i){
        str_one[s[i]]++;
        str_two[t[i]]++;
       }

       return str_one == str_two;
    }
};
