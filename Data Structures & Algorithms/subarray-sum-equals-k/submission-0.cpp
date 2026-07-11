class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res= 0 , currSum = 0;

        unordered_map<int,int> prefixSum;
        prefixSum[0] =1;
        for(int n : nums){
            currSum += n;
            int diff = currSum - k ;
            res += prefixSum.count(diff) ? prefixSum[diff] : 0;
            prefixSum[currSum]++;
        }
        return res;
    }
};