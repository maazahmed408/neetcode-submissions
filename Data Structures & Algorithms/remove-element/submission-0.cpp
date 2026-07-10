class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> output;

        for(int num : nums){
            if(num != val){

                output.push_back(num);
            }
        }
        for(int i = 0; i < nums.size();++i){
            if( i >= output.size()) break;
            nums[i] = output[i];
        }

        return output.size();
    }
};