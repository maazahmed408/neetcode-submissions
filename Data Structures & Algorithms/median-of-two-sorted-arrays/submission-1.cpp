class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> m = nums1.size() <= nums2.size() ? nums1:nums2 ;
        vector<int> n = nums1.size() > nums2.size() ? nums1:nums2 ;

        int low = 0;
        int high = m.size();

        while(low <= high){
            int x = (low + high)/2;
            int y = ((int)m.size()+(int)n.size()+1)/2 - x;

            int Aleft = x == 0?INT_MIN : m[x-1];
            int Aright = x == m.size() ? INT_MAX : m[x];
            int Bleft = y == 0?INT_MIN : n[y-1];
            int Bright = y == n.size() ? INT_MAX : n[y] ;

            if(Aleft <= Bright && Bleft <= Aright){
                double median = (m.size() + n.size())%2 == 0 ? (double)(max(Aleft,Bleft) + min(Aright,Bright))/2 : max(Aleft,Bleft);
                return median;
            }else if(Bleft > Aright){
                low = x+1;
            }else if(Aleft > Bright){
                high = x - 1;
            }
        }

        return 0.0;
    }
};
 