class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int l = 0;
        int r = n - 1;

        while(l<r){
            int mid = (r-l)/2 + l;

            if(nums[mid] > nums[n-1]){
                l = mid + 1;
            }else{
                r = mid;
            }
        }

        int pivot = l;

        if(target >= nums[pivot] && target <= nums[n-1]){
            l = pivot;
            r = n - 1;
        }else{
            l = 0;
            r = pivot - 1;
        }

        while(l <= r){
            int mid = (r-l)/2 + l;

            if(nums[mid] < target){
                l = mid + 1;
            }else if(nums[mid] > target){
                r= mid - 1;
            }else{
                return mid;
            }
        }

        return -1;

    }
};
