class Solution {
    unordered_map<int,vector<int>> adj;
    unordered_set<int> safe;
    unordered_set<int> visited;
    vector<int> res;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
     for(int i = 0 ; i < numCourses; ++i){
            adj[i] = {};
        }

        for(auto prereq : prerequisites){
            int n1 = prereq[0];
            int n2 = prereq[1];
            adj[n1].push_back(n2);
        }

        for(int i = 0 ; i < numCourses ; ++i){
            if(!dfs(i)) return {};
        }

        return res;
        
    }

    bool dfs(int i){
        if(visited.count(i)) return false;
        if(safe.count(i)) return true;

        visited.insert(i);

        for(int n : adj[i]){
            if(!dfs(n)) return false;
        }
        visited.erase(i);
        safe.insert(i);
        res.push_back(i);

        return true;
    }
};
