class Solution {
public:
    void dfs(int i, int j, vector<vector<bool>> &vis, vector<vector<char>> &grid, int m, int n){
      if(i<0||j<0|| i>=m|| j>=n||vis[i][j]||grid[i][j]!='1')return;
      vis[i][j] = true;
      dfs(i+1,j,vis, grid, m, n);
      dfs(i,j+1,vis, grid, m, n);
      dfs(i-1,j,vis, grid, m, n);
      dfs(i,j-1,vis, grid, m, n);

    }
    int numIslands(vector<vector<char>>& grid) {
      int count = 0;
      vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
      for(int i = 0; i < grid.size();i++){
        for(int j = 0; j<grid[0].size();j++){
          if(grid[i][j]=='1'&& !visited[i][j]){
            dfs(i,j,visited, grid, grid.size(), grid[0].size());
            count++;
          }
        }
      }
      return count;
    }
};