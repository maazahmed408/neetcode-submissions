class Solution {
public:
    int uniquePaths(int m, int n) {
       int i = m-1;
       int j = n-1;
       int totalWay = 0;
       vector<vector<int>> dp(m, vector<int>(n, -1));
        totalWay =  searchPath(i,j,dp);

       return totalWay; 
    }

    int searchPath(int i, int j, vector<vector<int>>& dp ){
        if(i == 0 && j==0){
            return 1;
        }

        if(i < 0 || j<0){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int up = searchPath(i-1,j,dp);
        int left = searchPath(i,j-1,dp);

        return dp[i][j] = up + left;
    }

};

// up 
// left
