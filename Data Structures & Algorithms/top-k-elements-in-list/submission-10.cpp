class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hashmap;

        for(int i = 0; i< nums.size(); ++i){
          hashmap[nums[i]]++;
        }

        vector<vector<int>> bucket(nums.size()+1);

        for(auto it : hashmap){
          bucket[it.second].push_back(it.first);
        }

        vector<int> output;
        int count = 0;

        for(int i = bucket.size()-1; i>0; i--){
          if(count < k && !bucket[i].empty()){
             for(int j : bucket[i]){
              output.push_back(j);
              count++;
              if(count > k){
                break;
              }
             } 
          }
        }

        return output;
    }
};
