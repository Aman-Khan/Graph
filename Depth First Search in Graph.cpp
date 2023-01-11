 void dfs(int i, vector<int> adj[], vector<int> &ans, vector<int> &visited, int v){

        visited[i]=1;
        ans.push_back(i);

        for(auto it: adj[i]){
            if(!visited[it]){
                dfs(it, adj, ans, visited, v);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> visited(V,0);
        vector<int> ans;
        int i=0;
        dfs(i, adj, ans, visited, V);
        return ans;
    }
