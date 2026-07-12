class Solution {
    vector<vector<int>> visited;
    int perimeter = 0;
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        visited.resize(rows,vector<int>(cols,0));

        for(int i = 0 ; i < rows ; ++i){
            for(int j =0 ; j <cols;++j){
                if(grid[i][j] == 1){
                    dfs(i,j,grid);
                    break;
                }
            }
        }

        return perimeter;
    }

    void dfs(int r, int c, vector<vector<int>>& grid){
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size()) return;

        if(grid[r][c] == 0 || visited[r][c] == 1) return;

        visited[r][c] = 1;
        if(r-1 < 0) perimeter++;
        if(c-1 < 0) perimeter++;
        if(r+1 >= grid.size()) perimeter++;
        if(c+1 >= grid[0].size()) perimeter++;
        if(r+1 < grid.size()  && grid[r+1][c]==0) perimeter++;
        if(c+1 < grid[0].size() && grid[r][c+1] == 0) perimeter++;
        if(r-1 >= 0  && grid[r-1][c] == 0) perimeter++;
        if(c-1 >= 0 && grid[r][c-1] == 0) perimeter ++;

        dfs(r-1,c,grid);
        dfs(r+1,c,grid);
        dfs(r,c-1,grid);
        dfs(r,c+1,grid);

    }
};