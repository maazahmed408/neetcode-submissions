class Solution {
    vector<int> dp;
public:
    int numDecodings(string s) {
        dp.resize(s.size(),-1);
        return countWays(s,0);
    }

    int countWays(string& s, int i) {
        if (i == s.size()) return 1;
        if (s[i] == '0') return 0;

        if(dp[i] != -1) return dp[i];

        int ways = countWays(s, i + 1);  // take one digit: s[i]

        if (i + 1 < s.size() && isValid(s.substr(i, 2))) {
            ways += countWays(s, i + 2);  // take two digits: s[i], s[i+1]
        }

    return dp[i] = ways;
}


    bool isValid(string s) {
        if (s.size() > 1 && s[0] == '0') return false; // no leading zero
        int num = stoi(s);
        return num >= 1 && num <= 26;
    }
};
