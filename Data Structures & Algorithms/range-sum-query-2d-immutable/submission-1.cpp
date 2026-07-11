class NumMatrix {
    vector<vector<int>> prefixMatrix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return;

        int rows = matrix.size() + 1;
        int cols = matrix[0].size() + 1;

        prefixMatrix.resize(rows,vector<int>(cols,0));

        for(int i = 0 ; i < rows-1; ++i){
            int prefix = 0;
            for(int j = 0 ; j < cols-1 ; ++j){
                prefix  += matrix[i][j];
                int above = prefixMatrix[i][j+1];
                prefixMatrix[i+1][j+1] = above + prefix;  
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1 = row1 + 1; col1 = col1+1; row2 = row2+1; col2 = col2+1;

        int bottomRight = prefixMatrix[row2][col2];
        int above = prefixMatrix[row1-1][col2];
        int left = prefixMatrix[row2][col1-1];
        int topLeft = prefixMatrix[row1-1][col1-1];

        return  bottomRight - above - left + topLeft;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */