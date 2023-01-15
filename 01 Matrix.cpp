    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> visited(n, vector<int>(m, INT_MAX));
        queue<pair<pair<int, int>, int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]==0){
                    q.push({{i, j}, 0});
                    visited[i][j]=0;
                }
            }
        }

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int nrow = drow[i]+x;
                int ncol = dcol[i]+y;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && mat[nrow][ncol]!=0){
                    if(visited[nrow][ncol]>steps+1){
                        visited[nrow][ncol]=steps+1;
                        q.push({{nrow, ncol}, steps+1});
                    }
                }
            }
        }
        return visited;
    }
