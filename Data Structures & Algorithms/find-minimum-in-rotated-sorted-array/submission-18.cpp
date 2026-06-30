class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size() -1 ;
        int l = 0 , r = n;
        while(l<=r){
            int mid = (r-l)/2 + l;

            if(nums[n] < nums[mid]){
                l = mid + 1;
            }else if(mid -1  >= 0 && nums[mid -1] < nums[mid]){
                r = mid -1 ;    
            }else{
                return nums[mid];
            }
        }

        return -1;
    }
};
