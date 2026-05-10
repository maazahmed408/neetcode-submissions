class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Always binary-search the smaller array
        vector<int>& A = (nums1.size() <= nums2.size()) ? nums1 : nums2;
        vector<int>& B = (nums1.size() <= nums2.size()) ? nums2 : nums1;

        int total = (int)A.size() + (int)B.size();
        int half = total / 2;

        int l = 0, r = (int)A.size(); // partition i in [0..A.size()]

        while (l <= r) {
            int i = l + (r - l) / 2;   // elements from A on left
            int j = half - i;          // elements from B on left

            int Aleft  = (i == 0) ? INT_MIN : A[i - 1];
            int Aright = (i == (int)A.size()) ? INT_MAX : A[i];
            int Bleft  = (j == 0) ? INT_MIN : B[j - 1];
            int Bright = (j == (int)B.size()) ? INT_MAX : B[j];

            if (Aleft <= Bright && Bleft <= Aright) {
                // correct partition
                if (total % 2 == 1) {
                    return (double)min(Aright, Bright);
                } else {
                    int leftMax = max(Aleft, Bleft);
                    int rightMin = min(Aright, Bright);
                    return (leftMax + rightMin) / 2.0;
                }
            } else if (Aleft > Bright) {
                r = i - 1;  // move partition left
            } else {
                l = i + 1;  // move partition right
            }
        }

        return 0.0; // unreachable for valid inputs
    }
};
