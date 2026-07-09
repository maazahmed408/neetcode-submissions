class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int maxArea = 0;

        for(int i = 0 ; i<rows;++i){
            for(int j = 0; j <cols;++j){
                if(grid[i][j] == 1){
                    int area = bfs(grid,i,j);
                    maxArea = max(maxArea,area);
                }
            }
        }

        return maxArea;
    }

    int bfs(vector<vector<int>>& grid , int r, int c){

        queue<pair<int,int>> q;
        grid[r][c] = 0;
        q.push({r,c});
        int area = 1;

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,-1,0,1};

        while(!q.empty()){
            auto [row,col] = q.front();
            q.pop();
            for(int i = 0; i < 4 ; ++i){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow >= grid.size() || ncol >= grid[0].size() || nrow < 0 || ncol < 0 || grid[nrow][ncol] == 0) continue;
                q.push({nrow,ncol});
                grid[nrow][ncol] = 0;
                area++; 
            }

        }
        return area;
    }
};
