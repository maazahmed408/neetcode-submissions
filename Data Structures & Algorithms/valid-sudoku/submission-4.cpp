class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> hashset;

        int ROW = board.size() - 1;
        int COL = board[0].size() - 1;

        for(int i = 0; i <= ROW ; i++){
            for(int j = 0; j <=COL ; j++){
                if(board[i][j] == '.'){
                    continue;
                }
                string rowKey = to_string(i) + "row" + to_string(board[i][j]);
                string colKey = to_string(j) + "col" + to_string(board[i][j]);
                string boxKey = to_string((i/3) + ((j/3) * 3 )) + "box" + to_string(board[i][j]);

                if(hashset.count(rowKey) || hashset.count(colKey) || hashset.count(boxKey)){
                    return false;
                }

                hashset.insert(rowKey);
                hashset.insert(colKey);
                hashset.insert(boxKey);
            }
        }

        return true;
    }
};
