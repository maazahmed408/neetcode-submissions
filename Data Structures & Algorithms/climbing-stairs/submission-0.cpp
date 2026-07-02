class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return search(n,dp);
    }

    int search(int i, vector<int>& dp ){
       if (i == 0){
        return 1;
       } 
       if(i == 1){
        return 1;
       }

       if(dp[i] != -1){
        return dp[i];
       }

        int left = search(i-1,dp);
        int right = search(i-2,dp);

        return dp[i] = left + right;
    }
};
