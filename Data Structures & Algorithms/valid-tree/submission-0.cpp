class Solution {
    unordered_map<int,vector<int>> adj;
    unordered_set<int> visited; 
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        for(int i = 0 ; i < n; ++i){
            adj[i] = {};
        }
        for( auto edge : edges){
            int n1 = edge[0];
            int n2 = edge[1];

            adj[n1].push_back(n2);
            adj[n2].push_back(n1);
        }

        return dfs(0,-1) && visited.size() == n;
    }

    bool dfs(int node,int prevNode){
        if(visited.count(node)) return false;

        visited.insert(node);

        for(int nextNode : adj[node]){
            if(nextNode == prevNode) continue;
            if(!dfs(nextNode,node)) return false;
        }

        return true;

    }
};
