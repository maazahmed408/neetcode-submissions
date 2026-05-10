class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxA = 0;
        for(int i = 0; i< heights.size(); i++){
            for(int j = i+1; j< heights.size(); j++){
                int h = min(heights[i],heights[j]);
                int area = h * (j-i);
                maxA = max(maxA,area);
            }
            cout<<maxA<<endl;
        }

        return maxA;
    }
};
