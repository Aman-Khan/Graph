    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> visited(V, 0);
        vector<int> ans;
        
        queue<int> q;
        q.push(0);
        visited[0]=1;
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            ans.push_back(temp);
            for(auto i:adj[temp]){
                if(visited[i]==0){
                    q.push(i);
                    visited[i]=1;
                }
            }
        }
        return ans;
    }
