class Solution {
public:
    bool isCycle(int node, vector<vector<int>>&adj, vector<int>& state){
      if(state[node]==1)return true;
      if(state[node]==2)return false;
      
      state[node]=1;
      for(int neighbor: adj[node]){
        if(isCycle(neighbor, adj, state)){
          return true;
        }
      }
      state[node]=2;
      return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
      vector<vector<int>> adj(numCourses);

      for(auto& req:prerequisites){
        adj[req[1]].push_back(req[0]);
      }

      vector<int> state(numCourses, 0);

      for(int i = 0; i<numCourses;i++){
        if(state[i]==0){
          if(isCycle(i, adj, state)){
            return false;
          }
        }
      }
      return true;
    }
};