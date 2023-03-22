    void reverseCon(vector<vector<int>>& graph){
        int n = graph.size();
        vector<vector<int>> graph2(n);
        for(int i=0; i<n; i++){
            for(auto j:graph[i]){
                graph2[j].push_back(i);
            }
        }
        graph = graph2;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        queue<int> q;
        reverseCon(graph);
        int n = graph.size();
        vector<int> safeNodes(n, 0);
        vector<int> indegree(n, 0);
        for(auto con:graph){
            for(auto i:con){
                indegree[i]++;
            }
        }
        for(int i=0; i<n; i++){
            if(indegree[i]==0){
                q.push(i);
                safeNodes[i]=1;
            }
        }
        while(!q.empty()){
            int node = q.front();
            safeNodes[node]=1;
            q.pop();
            for(auto i: graph[node]){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i) ;
                }
            }
        }
        for(int i=0; i<n; i++){
            if(safeNodes[i]==1){
                ans.push_back(i);
            }
        }
        return ans;
    }
