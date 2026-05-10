class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxLeft ;
        int maxRight ;

        int l = 0;
        int r = heights.size() - 1;
        int maxArea = INT_MIN;

        while(l < r){
            int area = min(heights[l] , heights[r]) * (r-l);
            maxArea = max(area , maxArea);
            if(heights[l] <= heights[r]){
                ++l;
            }else{
                --r;
            }
        }

        return maxArea;
    }
};
