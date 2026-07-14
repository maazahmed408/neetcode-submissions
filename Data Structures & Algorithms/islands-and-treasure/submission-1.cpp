class Solution {
    vector<vector<int>> visited;
    int rows;
    int cols;
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        visited.resize(rows,vector<int>(cols,0));
        int INF = 2147483647;
        queue<pair<int,int>> q;

        for(int r = 0 ; r < rows; r++){
            for(int c = 0 ; c < cols; c++){
                if(grid[r][c] == 0){
                    q.push({r,c});
                }
            }
        }

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,-1,0,1};

        while(!q.empty()){
            auto toPop = q.front();
            auto [r,c] = toPop;
            q.pop();
            for(int i = 0 ; i < 4 ; ++i){
                int nrow = drow[i] + r;
                int ncol = dcol[i] + c;

                if(nrow < 0 || ncol < 0 || nrow >= rows || ncol >= cols || grid[nrow][ncol]==-1 || visited[nrow][ncol]==1 || grid[nrow][ncol]== 0 ) 
                    continue;
                grid[nrow][ncol] = grid[r][c] +1;
                visited[nrow][ncol] = 1;
                q.push({nrow,ncol});
            }
        }


    }
};
