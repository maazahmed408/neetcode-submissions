class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> ds;
        sort(candidates.begin(),candidates.end());
        findComb(0,target,ds,candidates);
        return res;
    }

    void findComb(int i , int target,vector<int> ds,vector<int>& candidates){
        if(i == candidates.size()|| target == 0){
            if(target == 0){
                res.push_back(ds);
            }
            return;
        }

        
        for(int j = i ; j < candidates.size();++j){
            if(j>i && candidates[j] == candidates[j-1]) continue;

            if(candidates[j] > target) break;

            ds.push_back(candidates[j]);
            findComb(j+1,target-candidates[j],ds,candidates);
            ds.pop_back();
            
        }
    }
};
