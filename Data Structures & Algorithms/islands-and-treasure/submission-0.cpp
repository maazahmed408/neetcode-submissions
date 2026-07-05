class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int,int>> q;

        for(int i = 0 ; i < rows;++i){
            for(int j = 0; j <cols;++j){
                if(grid[i][j] == 0){
                    q.push({i,j});
                }
            }
        }
        int distance = 0;
        while(!q.empty()){
            auto [r,c] = q.front();
            // grid[r][c] = distance;
            q.pop();
            int drow[] = {-1,0,1,0};
            int dcol[] = {0,-1,0,1};

            for(int i = 0 ; i<4; ++i){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if(nrow >= 0 && ncol >= 0 && nrow < rows && ncol < cols && grid[nrow][ncol] == 2147483647){
                    grid[nrow][ncol] = grid[r][c] + 1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
};
