class Solution {
public:
    bool cycle(vector<int>adj[], int curr, vector<int>&vis, vector<int>&pathvis) {
        vis[curr]=1;
        pathvis[curr]=1;
        for(auto i: adj[curr]) {
            if(!vis[i]) { //as long as we are going forward with unknown ones
                if(cycle(adj,i,vis,pathvis)) return true;
            }
            else {
                if(pathvis[i]) {
                    return true;
                }
            }
        }
        pathvis[curr]=0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        vector<int>vis(numCourses), pathvis(numCourses);
        //building the adjacency list
        for(int i=0; i<prerequisites.size(); i++) {
            int curr = prerequisites[i][0], prereq = prerequisites[i][1];
            adj[curr].push_back(prereq);
        }

        //check to see if there are any cycles...
        for(int i=0; i<numCourses; i++) {
            if(!vis[i]) {
                if(cycle(adj,i,vis,pathvis)) return false;
            }
        }
        return true;
    }
};
