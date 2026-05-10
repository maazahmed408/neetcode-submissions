class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ROWS = matrix.size() - 1;
        int COLS = matrix[0].size() - 1;

        int top = 0;
        int bottom = ROWS;
        int rowMid = 0;

        while(top<=bottom){
            int mid = (bottom-top)/2 + top ;
            if(matrix[mid][0] == target){
                return true;
            }else if(matrix[mid][0] < target ){
                top = mid + 1;
                rowMid = mid;
            }else{
                bottom = mid -1;
            }
        }

        int l = 0;
        int r = COLS;

        while(l <= r){
            int mid = (r-l)/2 + l;

            if(matrix[rowMid][mid] == target){
                return true;
            }else if(matrix[rowMid][mid] < target){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }

        return false;
    }
};
