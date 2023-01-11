//Approach
//using visited array to track if node is visited or not 
//if find any node which is not visited count that (consider it as starting point to traverse city) and visit all city using starting node and mark city as visited.
//now we know all unvisited cities can't be visited using same path so, check for other paths as starting point(remember city path shouldn't be visited previously.
//

  void dfs(int i, vector<vector<int>> &adj, vector<bool>& visited, int v){
        visited[i]=1;
        for(int it=0; it<v; it++){
            if(it!=i && adj[i][it]==1 && !visited[it]){
                dfs(it, adj, visited, v);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<bool> visited(V,0);
        int cnt=0;
        for(int i=0; i<V; i++){
            if(!visited[i]){
                cnt++;
                dfs(i, adj, visited, V);
            }
        }
        return cnt;
    }
