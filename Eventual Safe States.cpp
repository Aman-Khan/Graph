    bool dfs(int ind, vector<int> adj[], vector<bool>& vis, vector<bool>& pathVis){
        vis[ind]=1;
        pathVis[ind]=1;
        bool isSafe = true;
        for(auto i : adj[ind]){
            if(!vis[i]){
                if(!dfs(i, adj, vis, pathVis)) return false;
            }
            else if(pathVis[i]){
                return false;;
            }
        }
        if(!isSafe) return false;
        pathVis[ind]=0;
        return true;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<bool> vis(V, 0);
        vector<bool> pathVis(V, 0);
        vector<int> safeNodes;
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i, adj, vis, pathVis);
            }
        }

        for(int i=0; i<V; i++){
            if(!pathVis[i]) safeNodes.push_back(i);
        }
        return safeNodes;
    }
