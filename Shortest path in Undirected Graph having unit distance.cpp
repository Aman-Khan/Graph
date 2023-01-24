void createAdj(vector<vector<int>>& edges, vector<int> adj[]){
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
    }
    
    
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int> adj[N];
        createAdj(edges, adj);
        
        vector<int> cost(N, 1e9);
        cost[src]=0;
        queue<int> q;
        q.push(src);
        
        while(!q.empty()){
        
            int node = q.front();
            q.pop();
            for(auto i:adj[node]){
                if(cost[node]+1<cost[i]){
                    cost[i]=cost[node]+1;
                    q.push(i);
                }
            }
        }
        for(int i=0; i<N; i++){
            if(cost[i]==1e9){
                cost[i]=-1;
            }
        }
        return cost;
    }
