class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() -1;
        while(l<r){
            int mid = (r-l)/2 + l;
            if(nums[mid]>nums[r]){
                l = mid +1;
            }else{
                r = mid;
            }
        }

        if(binarySearch(0,l-1,target,nums) == -1){
            return binarySearch(l,nums.size()-1,target,nums);
        }else{
            return binarySearch(0,l-1,target,nums);
        }


    }

    int binarySearch(int start , int end,int target, vector<int>& nums){
        int l = start;
        int r = end;
          while(l<=r){
            int mid = (r-l)/2 + l;
            if(nums[mid]<target){
                l = mid +1;
            }else if(nums[mid] > target){
                r = mid -1;
            }else{
                return mid;
            }
        }

        return -1;
    }
};
