class Solution {
public:
    int trap(vector<int>& height) {
        int maxLeft = height[0];
        int maxRight = height[height.size()-1];

        int l = 1;
        int r = height.size() - 2;
        int maxArea = 0;

        while(l<=r){
            int area = 0;
            if(maxLeft <= maxRight){
                area = min(maxLeft,maxRight) - height[l];
                maxLeft = max(height[l],maxLeft);  
                ++l;

            }else{
                area = min(maxLeft,maxRight) - height[r];
                maxRight = max(height[r],maxRight);
                --r;
            }

            maxArea += area>0?area:0;
        }

        return maxArea;
    }
};
