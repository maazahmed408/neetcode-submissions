class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> count(nums.size()+1);
        vector<int> output;
        unordered_map<int,int> hashmap;
        for(int num : nums){
            hashmap[num]++;
        }
        for(auto& [number, freq] : hashmap){
            count[freq].push_back(number);
        }

        for(int i = count.size()-1; i > 0 ; --i){
            if(count[i].size() >= 1){
                for(int num : count[i]){
                    output.push_back(num);
                    --k;
                    if(k == 0) return output;
                }
            }

      
        }

        return output;
    }
};
