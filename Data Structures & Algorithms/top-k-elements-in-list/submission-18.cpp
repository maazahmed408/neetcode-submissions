class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> output;
        unordered_map<int, int> countMap;
        for (int n : nums) {
            countMap[n]++;
        }

        vector<vector<int>> bucket(nums.size() + 1, vector<int>());

        for (auto& [num, freq] : countMap) {
            bucket[freq].push_back(num);
        }

        for (int i = bucket.size() - 1; i >= 0; --i) {
            for (int el : bucket[i]) {
                output.push_back(el);
                if (output.size() == k ) return output;
            }
        }

        return output;
    }
};
