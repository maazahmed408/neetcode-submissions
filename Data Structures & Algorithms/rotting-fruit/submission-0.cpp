class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        int freshCount = 0;
        int time = 0;
        queue<pair<pair<int,int>,int>> q;

        for(int i = 0; i<ROWS;++i){
            for(int j = 0; j<COLS;++j){
                if(grid[i][j] == 2){
                    q.push({{i,j},time});
                }
                if(grid[i][j]==1){
                    freshCount++;
                }
            }
        }
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,-1,0,1};

        while(!q.empty()){
            auto [coord , t] = q.front();
            auto [r,c] = coord;
            q.pop();
            time = max(t,time);
            for(int i = 0 ; i<4;i++){
                int nrow = r+drow[i];
                int ncol = c+dcol[i];
                if(nrow >= 0 && ncol >=0 && nrow <ROWS && ncol < COLS && grid[nrow][ncol] == 1){
                    grid[nrow][ncol] = 2;
                    q.push({{nrow,ncol},time+1});
                    --freshCount;
                }
            }
        }

        if(freshCount > 0) return -1;

        return time;
    }
};
