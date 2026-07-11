class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        unordered_map<int,int> countMap;

        for(int n : nums){
            countMap[n]++;
        }

        int threshold = nums.size() / 3;

        for(auto [number,count] : countMap){
            if(count > threshold)
            result.push_back(number);
        }

        return result;

    }
};