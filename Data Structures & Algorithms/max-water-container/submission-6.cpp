class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0 ;
        int r = heights.size() - 1;
        int maxArea = INT_MIN;

        while(l<r){
            int area = (r - l) * min(heights[l],heights[r]);
            maxArea = max(maxArea, area);

            if(heights[l] <= heights[r]){
                ++l;
            }else{
                --r;
            }
        }

        return maxArea;
    }
};
