class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
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

                if(nrow >= 0 && ncol >= 0 && nrow < rows && ncol < cols && grid[nrow][ncol]== INF){
                    grid[nrow][ncol] = grid[r][c] +1;
                    // grid[r][c] = 1;
                    q.push({nrow,ncol});
                } 
            }
        }


    }
};
