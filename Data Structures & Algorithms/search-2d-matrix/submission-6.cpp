class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ROWS = matrix.size() - 1;
        int COLS = matrix[0].size() - 1;
        
        int top = 0 ;
        int bottom = ROWS;

        while(top <= bottom){
            int mid = (bottom-top)/2 + top;

            if(matrix[mid][0] == target){
                return true;
            }else if(matrix[mid][0] <= target && matrix[mid][COLS] >= target){
                int l = 0;
                int r = COLS;

                while(l <= r){
                    int middle = (r-l)/2 + l;

                    if(matrix[mid][middle] == target){
                        return true;
                    }else if(matrix[mid][middle] < target){
                        l = middle + 1;
                    }else{
                       r = middle - 1;
                    }

                } 
                    return false;
            }else if(matrix[mid][0] < target){
                top = mid + 1;
            }else{
                bottom = mid - 1;
            }

        }
            return false;
    }
};
