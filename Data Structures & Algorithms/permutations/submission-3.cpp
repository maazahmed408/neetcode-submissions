class Solution {
    vector<vector<int>> res;
    vector<int> freq;
public:
    vector<vector<int>> permute(vector<int>& nums) {
         freq.resize(nums.size());
         dfs({},nums);

         return res;
    }

    void dfs(vector<int> ds, vector<int>& nums){

            if(ds.size() == nums.size()){
                res.push_back(ds);
                return;
            }        

        for(int i =0 ; i < nums.size();++i){
            if(!freq[i]){
                freq[i] = 1;
                ds.push_back(nums[i]);
                dfs(ds,nums);
                ds.pop_back();
                freq[i] = 0;
            }
        }
    }
};
