class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int ROWS = matrix.size();
        int COLS = matrix[0].size();
        int top = 0 , bottom = ROWS-1 ;

        while (top <= bottom){

            int rowMid = top + (bottom - top)/2;

            if(matrix[rowMid][0] < target){

                if(target > matrix[rowMid][COLS-1]){
                top = rowMid + 1;
                }else{
                   int left = 0;
                    int right = COLS-1;

                    while(left <= right){

                        int colMid = left + (right - left)/2;
                        cout<<matrix[rowMid][colMid];
                        if(target > matrix[rowMid][colMid]){
                            left = colMid + 1 ;
                        }else if(target < matrix[rowMid][colMid]){
                            right = colMid - 1;
        
                        }
                        else{
                            return true;
                        }

                        
                    }
                    return false;
                }
            }else if(matrix[rowMid][0] > target){
                bottom = rowMid - 1;
            }else{
                return true;
            }
            
        }

        return false;
    }
};
