class Solution {
     vector<string> digitToChar = {"", "", "abc", "def", "ghi", "jkl",
                                  "mno", "qprs", "tuv", "wxyz"};
    vector<string> res;

public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return res;
        backtrack(0, "", digits);
        return res;
    }

    void backtrack(int i , string curr, string& digits){
        if(curr.size() == digits.size()){
            res.push_back(curr);
            return;
        }

        string chars = digitToChar[digits[i] -'0'];
        for(char c : chars){
            backtrack(i+1,curr+c,digits);
         }
    }
};
