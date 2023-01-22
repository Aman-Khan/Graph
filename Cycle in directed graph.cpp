    bool dfs(int n, vector<int> adj[], vector<int>& visited, vector<int>& pathVis){
        visited[n]=1;
        pathVis[n]=1;
        
        for(int i=0; i<adj[n].size(); i++){
            if(!visited[adj[n][i]]){
                if(dfs(adj[n][i], adj, visited, pathVis)) return true;
            }
            else if(pathVis[adj[n][i]]) return true;
        }
        pathVis[n]=0;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> visited(V, 0);
        vector<int> pathVis(V, 0);
        for(int i=0; i<V; i++){
            if(!visited[i]){
                if(dfs(i, adj, visited, pathVis)) return true;
            }
        }
        return false;
    }
