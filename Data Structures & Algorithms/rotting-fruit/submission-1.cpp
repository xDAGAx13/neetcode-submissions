class Solution {
public:
    void bfs(){

    }
    int orangesRotting(vector<vector<int>>& grid) {
      int m = grid.size();
      int n = grid[0].size();
      int minTime = 0;
      vector<vector<bool>> visited(m, vector<bool>(n, false));
      queue<pair<pair<int,int>, int>>q;
      for(int i = 0; i <m;i++){
        for(int j = 0;j<n;j++){
          if(grid[i][j]==2)q.push({{i,j},0});
        }
      }

      while(q.size()>0){
        int i = q.front().first.first;
        int j = q.front().first.second;
        int time = q.front().second;
        q.pop();

        minTime = max(minTime, time);

        if(i-1>=0&&!visited[i-1][j]&& grid[i-1][j]==1){
          q.push({{i-1, j}, time+1});
          visited[i-1][j] = true;
        }

        if(j+1<n&&!visited[i][j+1]&& grid[i][j+1]==1){
          q.push({{i, j+1}, time+1});
          visited[i][j+1] = true;
        }
        if(i+1<m&&!visited[i+1][j]&& grid[i+1][j]==1){
          q.push({{i+1, j}, time+1});
          visited[i+1][j] = true;
        }
        if(j-1>=0&&!visited[i][j-1]&& grid[i][j-1]==1){
          q.push({{i, j-1}, time+1});
          visited[i][j-1] = true;
        }
      }

      for(int i = 0; i<m;i++){
        for(int j = 0; j<n;j++){
          if(grid[i][j]==1&& !visited[i][j]){
            return -1;
          }
        }
      }

      return minTime;
    }
};