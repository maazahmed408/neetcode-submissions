class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> ds;
        vector<int> freq(nums.size(),0);
        findPermute(ds,freq,nums);
        return res;
    }

    void findPermute(vector<int> ds , vector<int> freq,vector<int>& nums){
    if(ds.size() == nums.size()) {res.push_back(ds); return ;}

     for(int i = 0 ; i<nums.size();++i){        
        if(!freq[i]){
            ds.push_back(nums[i]);
            freq[i] = 1;
            findPermute(ds,freq,nums);
            freq[i] = 0;
            ds.pop_back();
        }
     }
    }
};
