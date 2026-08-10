class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        if(nums2.size() < nums1.size()){
            swap(nums2,nums1);
        }

        int total = nums1.size() + nums2.size();
        int half = (total + 1)/2;

        int l = 0;
        int r = nums1.size();

        while(l <= r){
            int x = (r-l)/2 + l;
            int y = half - x;

            int Aleft = x > 0 ? nums1[x-1] : INT_MIN;
            int Bleft = y > 0 ? nums2[y-1] : INT_MIN;
            int Aright = x < nums1.size() ? nums1[x] : INT_MAX;
            int Bright = y < nums2.size() ? nums2[y] : INT_MAX;

            if(Bleft <= Aright && Aleft <= Bright){
                if(total % 2 != 0){
                    return max(Aleft,Bleft);
                }else{
                    return (max(Aleft,Bleft) + min(Aright,Bright))/2.0 ;
                }
           }else if(Aleft > Bright){
            r = x - 1;
           }else{
            l = x + 1;
           }
        }

        return 0.0; 
    }
};
