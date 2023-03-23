    void createAdj(vector<vector<int>>& edges, vector<int> adj[]){
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
    }
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int> adj[N];
        createAdj(edges, adj);
        vector<int> dis(N, 1e9);
        dis[src]=0;
        
        queue<int> q;
        q.push(src);
        vector<bool> vis(N, 0);
        vis[src]=1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto i:adj[node]){
                if(!vis[i]){
                    int d = dis[node]+1;
                    q.push(i);
                    dis[i] = min(dis[i], d);
                    vis[i] = 1;
                }       
            }
        }
        for(int i=0; i<N; i++){
            if(dis[i]==1e9){
                dis[i]=-1;
            }
        }
        return dis;
    }
