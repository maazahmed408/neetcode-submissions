class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ROWS = matrix.size()-1;
        int COLS = matrix[0].size()-1;

        int top = 0;
        int bottom = ROWS;

        while(top <= bottom){
            int mid = top + (bottom - top)/2;
            if( target > matrix[mid][0] && target < matrix[mid][COLS] ){
                bool output = binarySearch(matrix, target, mid, COLS);
                return output ? true : false;
            }else if(matrix[mid][0] < target && target > matrix[mid][COLS]){
                top = mid + 1;
            }else if(matrix[mid][0] > target){
                bottom = mid-1;
            }else{
                return true;
            }
        }

        return false;
    }

    bool binarySearch(vector<vector<int>>& matrix , int target , int row , int COLS){
        int l = 0;
        int r = COLS;

        while(l<=r){
            int mid = l + (r-l)/2;
            if(target > matrix[row][mid]){
                //discard first part
                l = mid + 1;
            }else if(target < matrix[row][mid]){
                //discard last part
                r = mid -1;
            }else{
                return true;
            }
        }

        return false;
    }
};
