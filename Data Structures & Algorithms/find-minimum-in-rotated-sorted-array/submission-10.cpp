class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size();
        int minimum = INT_MAX;

        while(l<=r){
            int mid = (r-l)/2 + l;

            if(nums[mid] > nums[nums.size()-1]){
                l = mid + 1;
            }else{
                r = mid - 1;
                minimum = min(minimum,nums[mid]);
            }
        }

        return minimum;
    }
};
