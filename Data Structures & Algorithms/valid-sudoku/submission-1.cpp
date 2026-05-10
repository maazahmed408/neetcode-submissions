class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> seen;
        
        //should not repeat in row
        //should not repeat in col
        //should not be in box

        //formula for the box is r/3 *3 + c

        for(int i = 0; i< 9 ; ++i){
            for(int j = 0; j<9; ++j){

                if(board[i][j] == '.'){
                    continue;
                }

                int box = (i /3) * 3 + (j/3);

                string key1 = "row" + to_string(i) + board[i][j];
                string key2 = "col" + to_string(j) + board[i][j];
                string key3 = "box" + to_string(box) + board[i][j];
                if(seen.count(key1) || seen.count(key2) || seen.count(key3)){
                    return false;
                }else{
                    seen.insert(key1);
                    seen.insert(key2);
                    seen.insert(key3);
                }
            }
        }

        return true;
    }
};
