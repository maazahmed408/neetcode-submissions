class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));

        for(int c = 0 ; c < cols ; ++c){
            dfs(0,c,pacific,heights[0][c],heights);
            dfs(rows-1,c,atlantic,heights[rows-1][c],heights);
        }

        for(int r = 0 ; r < rows ; ++r){
            dfs(r,0,pacific,heights[r][0],heights);
            dfs(r,cols-1,atlantic,heights[r][cols-1],heights);
        }

        vector<vector<int>> res;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (pacific[r][c] && atlantic[r][c]) {
                    res.push_back({r, c});
                }
            }
        }

        return res;

    }

    void dfs(int r ,int c,  vector<vector<bool>>& visit,int prevHeight, vector<vector<int>>& heights){
        if(r < 0 || c < 0 || r >= heights.size() || c >= heights[0].size() || visit[r][c] || prevHeight > heights[r][c]){
            return ;
        }

        visit[r][c] = true;

        dfs(r-1,c,visit,heights[r][c],heights);
        dfs(r+1,c,visit,heights[r][c],heights);
        dfs(r,c-1,visit,heights[r][c],heights);
        dfs(r,c+1,visit,heights[r][c],heights);
    }
};
