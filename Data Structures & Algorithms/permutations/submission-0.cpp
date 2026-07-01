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
        if(ds.size() == nums.size()){
            res.push_back(ds);
            return;
        }  
        for(int j = 0 ; j < nums.size();++j){
            if(!freq[j]){
                ds.push_back(nums[j]);
                freq[j] = 1;
                findPermute(ds,freq,nums);
                freq[j]= 0;
                ds.pop_back();
            }


        }
     
    }
};
