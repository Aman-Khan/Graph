void topo(int node, vector<bool>& vis, vector<int> adj[], stack<int>& st){
        vis[node]=1;
        for(auto i:adj[node]){
            if(!vis[i]) topo(i, vis, adj, st);
        }
        st.push(node);
    }

	vector<int> topoSort(int V, vector<int> adj[]) 
	{
        vector<int> ans;
        stack<int> st;
        vector<bool> vis(V, 0);
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                topo(i, vis, adj, st);
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
	}
