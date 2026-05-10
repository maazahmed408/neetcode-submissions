class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      int postfix = 1;
      int prefix = 1;
      vector<int> output;
      output.push_back(prefix);

      for(int i = 1; i < nums.size(); ++i){
        prefix = prefix * nums[i-1];
        output.push_back(prefix);
      }


      for(int j = nums.size()-2; j >= 0 ; --j){
        postfix = postfix * nums[j+1];
        output[j] = output[j] * postfix;
      }

      return output;



    }
};
