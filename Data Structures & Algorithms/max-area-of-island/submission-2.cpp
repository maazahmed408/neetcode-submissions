class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int maxArea = 0;

        for(int i = 0 ; i<rows;++i){
            for(int j = 0; j <cols;++j){
                if(grid[i][j] == 1){
                    int area = dfs(grid,i,j);
                    maxArea = max(maxArea,area);
                }
            }
        }

        return maxArea;
    }

    int dfs(vector<vector<int>>& grid , int r, int c){
        if(r >= grid.size() || c >= grid[0].size() || r < 0 || c < 0 || grid[r][c] == 0)
            return 0;

        grid[r][c] = 0;
        int area = 1;

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,-1,0,1};
        for(int i = 0; i < 4 ; ++i){
            int nrow = r+ drow[i];
            int ncol = c + dcol[i];
            area += dfs(grid,nrow,ncol); 
        }

        return area;
    }
};
