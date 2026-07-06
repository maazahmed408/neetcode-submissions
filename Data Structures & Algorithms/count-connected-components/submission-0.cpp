class Solution {
    unordered_map<int,vector<int>> adj;
    unordered_set<int> visited;
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        for (int i = 0; i < n; ++i) {
            adj[i] = {};
        }
        int component = 0;

        for(auto& edge : edges){
            int n1 = edge[0];
            int n2 = edge[1];

            adj[n1].push_back(n2);
            adj[n2].push_back(n1); 
        }

        for(int i = 0 ; i < n ; i++){
            if(!visited.count(i)){
                dfs(i,-1);
                component++;
            } 
        }

        return component;
    }
    
    void dfs(int node,int prevNode){
        if(visited.count(node)) return ;

        visited.insert(node);

        for(auto nextNode : adj[node]){
            if(nextNode == prevNode) continue;
            dfs(nextNode,node);
        }
    }

};
