class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> output(nums.size()*2);
    
        int i = 0;
        int j = 0;
        while(i < output.size() ){
            while(j < nums.size()){
            output[i] = nums[j];
            ++i; ++j;
            }
            j = 0;
            while(j < nums.size()){
            output[i] = nums[j];
            ++i; ++j;
            }
            
        }

        return output;
    }
};