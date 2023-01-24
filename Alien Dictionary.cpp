    void func(string a, string b, map<char,vector<char>>& adj, map<char, bool>& visited){
        int n = a.size();
        int m = b.size();
        int i=0;
        for(; i<min(n, m); i++){
            visited[a[i]]=0;
            visited[b[i]]=0;
            if(a[i]!=b[i]){ 
                adj[a[i]].push_back(b[i]);
                break; 
            }
        }
        
    }
    
    void topo(int i, map<char, vector<char>>& adj, map<char, bool> &visited, stack<char>& st){
        visited[i]=1;
        
        for(auto ind:adj[i]){
            if(!visited[ind]){
                topo(ind, adj, visited, st);
            }
        }
        st.push(i);
    }
    
    string findOrder(string dict[], int N, int K) {
        map<char, vector<char>> adj;
        map<char, bool> visited;
        
        for(int i=1; i<N; i++){
            func(dict[i-1], dict[i], adj, visited);
        }
        
        stack<char> st;
        
        for(auto i:adj){
            if(!visited[i.first]){
                topo(i.first, adj, visited, st);
            }
        }
        
        string ans = "";
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
