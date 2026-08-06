class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() -1;
        int maxLeft = height[l];
        int maxRight = height[r];

        int totalArea = 0;

        while(l <= r){
            int area = 0;
            if(maxLeft <= maxRight){
                area = min(maxLeft,maxRight) - height[l];
                maxLeft = max(maxLeft, height[l]);
                ++l;
            }else{
                area = min(maxLeft,maxRight) - height[r];
                maxRight = max(maxRight,height[r]);
                --r;
            }

            totalArea += area > 0 ? area : 0; 
        }

        return totalArea;

    }
};
