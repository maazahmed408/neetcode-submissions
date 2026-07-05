class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int land = 0;

        queue<pair<int,int>> q;

        for(int i = 0; i <rows;++i){
            for(int j = 0 ; j < cols; ++j){
                if(grid[i][j] == '1'){
                    bfs(grid,i,j);
                    land++;
                }
            }
        }

        return land;
    }

    void bfs(vector<vector<char>>& grid, int r ,int c){
        queue<pair<int,int>> q;
        grid[r][c] = '0';
        q.push({r,c});

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,-1,0,1};

        while(!q.empty()){
            auto [row,col] = q.front();
            q.pop();
            for(int i = 0; i<4;++i){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow >= 0 && ncol >= 0 && nrow < grid.size() && ncol < grid[0].size() && grid[nrow][ncol] == '1'){
                    q.push({nrow,ncol});
                    grid[nrow][ncol] = '0';
                }
            }
        }    
    }
};
