    bool fillWithCol(int node, vector<int>& vis, vector<vector<int>>& graph, int col){
        vis[node]=col;
        for(auto i:graph[node]){
            if(vis[i]==-1){
                if(!fillWithCol(i, vis, graph, !col)) return false;
            }
            else if(vis[i]==col) return false;
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, -1);
        for(int i=0; i<n; i++){
            if(vis[i]==-1){
                if(!fillWithCol(i, vis, graph, 1)) return false;
            }
        }       
        return true;
    }
