    bool checkForCycle(int src, vector<int> adj[], vector<bool> &visited ){
        queue<pair<int, int>> q;
        q.push({src, -1});
        visited[src]=1;
        
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;

            q.pop();
            
            for(auto i:adj[node]){
                if(!visited[i]){
                    visited[i]=1;
                    q.push({i, node});
                }
                else if(i!=parent) return 1;
            }
        }
        return 0;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V, 0);
        for(int i=0; i<V; i++){
            if(!visited[i]){
                bool check = checkForCycle(i, adj, visited);
                if(check) return 1;
            }
        }
        return 0;
    }
