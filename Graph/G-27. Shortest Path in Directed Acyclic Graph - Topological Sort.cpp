    void createAdj(vector<vector<int>>& edges, vector<pair<int, int>> adj[]){
        for(auto i:edges){
            adj[i[0]].push_back({i[1], i[2]});
        }
    }
    void topoSort(int node, vector<bool>& vis, vector<pair<int, int>> adj[], stack<int>& st){
        vis[node]=1;
        for(auto i: adj[node]){
            if(!vis[i.first]) topoSort(i.first, vis, adj, st);
        }
        st.push(node);
    }
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<pair<int, int>> adj[N];
        createAdj(edges, adj);
        
        stack<int> st;
        vector<bool> vis(N, 0);
        
        for(int i=0; i<N; i++){
            if(!vis[i]){
                topoSort(i, vis, adj, st);
            }
        }

        vector<int> dis(N, 1e9);
        dis[0]=0;

        while(!st.empty()){
            int sou = st.top();
            st.pop();
            for(auto i: adj[sou]){
                int des = i.first;
                int d = i.second+dis[sou];
                dis[des] = min(dis[des], d);
            }
        }
         for(int i=0; i<N; i++){
            if(dis[i]==1e9) dis[i]=-1;
        }
        return dis;
    }
