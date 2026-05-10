class Solution {
public:
    int trap(vector<int>& height) {
       int maxL = height[0];
       int maxR = height[height.size()-1];
       int maxA = 0;

       int l = 1;
       int r = height.size() - 2;
       

       while(l<=r){
        int area;
        if(maxL <= maxR){
            area = maxL - height[l] ;
            maxL = max(maxL , height[l]);
            ++l;
        }else{
            area =  maxR - height[r];
            maxR = max(maxR, height[r]);
            --r;
        }
            cout<<area<<endl;
        if(area > 0){
            maxA += area;
        }
       }

       return maxA;
    }
};