void dfs(int ind, vector<int> adj[], vector<int>& vis, stack<int>& st){
        vis[ind]=1;
        
        for(auto i:adj[ind]){
            if(!vis[i]){
                dfs(i, adj, vis, st);
                st.push(i);
            }
        }
    }	
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> ans;
	    stack<int> st;
	    vector<int> vis(V, 0);
	    
	    for(int i=0; i<V; i++){
	        if(!vis[i]){
	            dfs(i, adj, vis, st);
	            st.push(i);
	        }
	    }
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}
