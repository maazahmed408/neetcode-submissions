class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0 ;
        int n = nums.size() -1 ;
        int r = n;

        while(l < r ){
            int mid = l + (r-l)/2;
            if(nums[mid] > nums[r]){
                l = mid + 1;
            }else{
                r = mid;
            }
        }

        if(target <= nums[n]){
            return binarySearch(nums,target,l,n);
        }else{
            return binarySearch(nums,target,0,l-1);
        }

        return -1;
    }
    int binarySearch (vector<int>& nums, int target, int left, int right){
        while(left <= right ){
            int mid = left + (right-left)/2;
            if(nums[mid] < target){
                left = mid + 1;
            }else if(nums[mid] > target){
                right = mid-1;
            }else{
                return mid;
            }
        }
        return -1;
    }
};
