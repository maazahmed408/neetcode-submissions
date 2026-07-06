class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        for(int c = 0; c<cols;c++){
            if(board[0][c] == 'O')
            dfs(0,c,board);

            if(board[rows-1][c] == 'O')
            dfs(rows-1,c,board);
        }

        for(int r = 0; r<rows;r++){
            if(board[r][0] == 'O')
            dfs(r,0,board);

            if(board[r][cols-1] == 'O')
            dfs(r,cols-1,board);
        }

        for(int i = 0; i<rows;++i){
            for(int j = 0; j<cols;++j){
                if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }

        for(int i = 0; i<rows;++i){
            for(int j = 0; j<cols;++j){
                if(board[i][j] == 'T') board[i][j] = 'O';
            }
        }
    }

    void dfs(int r , int c , vector<vector<char>>& board){
        int rows = board.size();
        int cols = board[0].size();

        if(r < 0 || c < 0 || r >= rows || c >= cols || board[r][c] != 'O') return;

        board[r][c] = 'T';

        dfs(r-1,c,board);
        dfs(r+1,c,board);
        dfs(r,c-1,board);
        dfs(r,c+1,board);
    }
};
