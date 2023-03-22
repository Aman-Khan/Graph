    void topo(vector<int>& ans, queue<int>& q, vector<int>& inDegree, vector<int> adj[]){
        while(!q.empty()){
            int temp = q.front();
            ans.push_back(temp);
            q.pop();
            for(auto i:adj[temp]){
                inDegree[i]--;
                if(inDegree[i]==0) q.push(i);
            }
        }
    }

	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> inDegree(V, 0);
	    for(int i=0; i<V; i++){
	        for(auto node: adj[i]){
	            inDegree[node]++;
	        }    
	    }
	    queue<int> q;
	    for(int i=0; i<V; i++){
	        if(inDegree[i]==0) q.push(i);
	    }
	    vector<int> ans;
	    topo(ans, q, inDegree, adj);
	    return ans;
	}
