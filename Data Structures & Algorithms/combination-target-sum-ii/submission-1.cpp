class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());

        dfs(0,target,{},candidates);

        return res;
    }

    void dfs(int i, int target, vector<int> ds,vector<int>& candidates){
        if(target == 0){
            res.push_back(ds);
            return;
        } 

        if(i >= candidates.size() || target < 0) return;

        for(int j = i ; j < candidates.size();++j){
            if(j > i && candidates[j] == candidates[j-1]) continue;
            if(candidates[j] > target) break;
            

                ds.push_back(candidates[j]);
                dfs(j+1,target-candidates[j],ds,candidates);
                ds.pop_back();

        }
        
    }
};
