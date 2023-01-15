//Approach 
//create visited matrix and fill with maximum value(INT_MAX)
//traverse the given matrix and store all 0 position with a step 0 in queue. (because for 0 nearest 0 aviable is him self) and also edit the value 0 in visited matrix;
//Now, till queue is not empty and for evey value in queue check all for direction if its not 0 then check for value in visited matrix if the step value in less than
//already entered value then update a new value in visited matrix.

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
