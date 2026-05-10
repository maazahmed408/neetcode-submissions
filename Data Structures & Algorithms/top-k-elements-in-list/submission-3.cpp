class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      unordered_map<int , int> hashmap ;
      vector<vector<int>> freq(nums.size()+1);
      vector<int> res;
      int num = nums.size();
        int i = 0;

      for(int i : nums){
        hashmap[i]++;
      }

      for(auto it : hashmap){
            freq[it.second].push_back(it.first);
      }

        for (int i = freq.size() - 1; i > 0; --i) {
            for (int n : freq[i]) {
                res.push_back(n);
                if (res.size() == k) {
                    return res;
                }
            }
        }
      return res;
    }
};