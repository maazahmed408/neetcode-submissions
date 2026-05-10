class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int ROWS = board.size() -1 ;
        int COLS = board[0].size() -1;
        unordered_set<string> res;
        for(int i = 0; i<= ROWS ;++i ){
            for(int j = 0; j<= COLS ;++j ){
                    if(board[i][j] == '.'){
                        continue;
                    }
                    int box = ((i/3)*3) + j/3;
                    string key1 = to_string(board[i][j]) + "row" + to_string(i);
                    string key2 = to_string(board[i][j]) + "col" + to_string(j);
                    string key3 = to_string(board[i][j])+ "box" + to_string(box);

                    if(res.count(key1) || res.count(key2) || res.count(key3)){
                        return false;
                    }else{
                        res.insert(key1);
                        res.insert(key2);
                        res.insert(key3);
                    }
                }
        }

        return true;
    }
};
