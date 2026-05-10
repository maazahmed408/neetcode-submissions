class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
     unordered_map<int ,int> count;

     for(int i : nums){
      count[i]++;
     }

     vector<vector<int>> res(nums.size() + 1);

    for(auto num : count){
      res[num.second].push_back(num.first);
    }

      vector<int> output;
      int seen = 0;

      for(int i = res.size() - 1; i >= 0; --i){
        if(seen >= k){
          break;
        }
        if(!res[i].empty() ){
          for(int i : res[i]){
             if(seen >= k){
            break;
        }
          output.push_back(i);
          ++seen;
          }
       
        }
      }

      return output;

    }
};