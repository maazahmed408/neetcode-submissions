class Solution {
    unordered_map<int,vector<int>> adj;
    unordered_set<int> visited;
    unordered_set<int> cycle;
    vector<int> res;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        for(int i = 0;i<numCourses;++i){
            adj[i] = {};
        }

        for(auto pre : prerequisites){
            adj[pre[0]].push_back(pre[1]);
        }
        
        for(int i = 0;i<numCourses;++i){
            if(!dfs(i)) return {};
        }

        return res;
        
    }

    bool dfs(int course){
        if(cycle.count(course)) return false;

        if(visited.count(course)) return true;

        cycle.insert(course);
        for(int pre : adj[course]){
            if(!dfs(pre)) return false;
        }
        cycle.erase(course);
        visited.insert(course);
        res.push_back(course);

        return true;
        
    }
};
