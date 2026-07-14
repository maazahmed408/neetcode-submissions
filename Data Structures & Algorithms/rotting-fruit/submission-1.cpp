class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<pair<int,int> , int>> q;
        int freshCount = 0;

        for(int i = 0 ; i < rows ; ++i){
            for(int j = 0 ; j < cols ; ++j){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                }else if(grid[i][j] == 1){
                    ++freshCount;
                }
            }
        }

        int time = 0;

        int drow[] = {-1,1,0,0};
        int dcol[] = {0,0,1,-1};

        while(!q.empty()){
            auto toPop = q.front();
            auto [coor,t] = toPop;
            auto[r,c] = coor;
            q.pop();
            time = max(time,t);
            
            for(int i = 0 ; i < 4 ; ++i){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if(nrow >= 0 && ncol >= 0 && nrow < rows && ncol < cols && grid[nrow][ncol] == 1){
                    grid[nrow][ncol] = 2;
                    --freshCount;
                    q.push({{nrow,ncol},t+1});
                }
            }

        }

        if(freshCount > 0 ) return -1;

        return time;
    }
};
