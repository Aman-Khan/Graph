    void createAdj(vector<vector<int>>& pre, vector<int> adjMat[]){
        for(auto i:pre){
            adjMat[i[0]].push_back(i[1]);
        }
    }
    bool checkForCycle(int node, vector<int> adjMat[], vector<int>& vis, vector<int>& pathVis){
        vis[node]=1;
        pathVis[node]=1;

        for(auto i:adjMat[node]){
            if(!vis[i]){
                if(checkForCycle(i, adjMat, vis, pathVis)) return true;
            }
            else if(pathVis[i]) return true;;
        }
        pathVis[node]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adjMat[numCourses];
        createAdj(prerequisites, adjMat);
        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);

        for(int i=0; i<numCourses; i++){
            if(!vis[i]){
                if(checkForCycle(i, adjMat, vis, pathVis)) return false;
            }
        }
        return true;
    }

//leetcode: https://leetcode.com/problems/course-schedule/
