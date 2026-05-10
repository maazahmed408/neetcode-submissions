class Solution {
public:
    int findMin(vector<int> &nums) {
        int result = INT_MAX;

        int l = 0; 
        int r = nums.size() - 1 ;
        int mid ;
        
        while(l<=r){
            if(nums[l] < nums[r]){
            return min(result, nums[l]);
        }
            mid = l + (r-l)/2;
            result = min(result, nums[mid] );

            if(nums[mid]>=nums[l]){
                //we are in left sorted portion
                l = mid + 1;
            }else{
                //we are in right sorted portion
                r = mid - 1;
            }
        }

        return result;
    }
};
