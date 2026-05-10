class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector <int> output (nums.size(),1);

        for(int i = 1 ; i < nums.size(); ++i){
            output[i] = nums[i-1] * output[i-1];
        }
        int right = 1;
        for(int j = nums.size()-2 ; j >= 0  ; j--){
            output[j] *= nums[j+1] * right;
            right = right  * nums[j+1];
        }

        return output;
    }
};
