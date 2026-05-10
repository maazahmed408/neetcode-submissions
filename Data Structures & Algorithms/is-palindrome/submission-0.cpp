class Solution {
public:
    bool isPalindrome(string s) {
        string newString = "";
        string r = "";

        for (char c : s){
            if((c >= 'a' && c<= 'z') || (c >= 'A' && c<= 'Z') || (c - '0' >= 0 && c-'0' <= 9) ){
                newString += tolower(c);
            }
        }

        r = newString;

        reverse(r.begin(), r.end());
        cout<<newString;
        cout<<r;

        if (r == newString){
        return true;
        }else{
            return false;
        }


    }
};
