class Solution {
public:
    int trap(vector<int>& height) {

        int area = 0;

        int l = 0;
        int r = height.size() - 1;

        int maxLeft = height[l];
        int maxRight = height[r];

        while(l<r){
            if(maxLeft <= maxRight){
                area += maxLeft < height[l] ? 0 : maxLeft - height[l];  
                ++l;
                maxLeft = max(maxLeft,height[l]);
            }else{
                area += maxRight < height[r] ? 0 : maxRight - height[r];
                --r;
                maxRight = max(maxRight,height[r]);
            }

        }

        return area;
    }
};