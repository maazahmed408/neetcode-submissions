class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>output(nums.size(),1);
        int prefix = 1;
        for(int i = 0; i<nums.size();++i){
            output[i] = prefix;
            prefix = prefix * nums[i];
        }
        int postfix = 1;
        for(int i = nums.size()-1;i>=0;--i){
            output[i] = output[i] * postfix;
            postfix = postfix * nums[i];
        }
        return output;
    }
    //[1,2,4,6] -> 
    //prefix [1,1,2,8]
    //suffix [48,24,6,1]
    //[48,24,12,8]

    //[     2,12 ,8]

};
