class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() -1;
        int maxLeft = height[l];
        int maxRight = height[r];

        int totalArea = 0;

        while(l < r){
            if(maxLeft <= maxRight){
                ++l;
                maxLeft = max(maxLeft,height[l]);
                totalArea += maxLeft - height[l];
            }else{
                --r;
                maxRight = max(maxRight,height[r]);
                totalArea += maxRight - height[r];
            }
        }

        return totalArea;

    }
};
