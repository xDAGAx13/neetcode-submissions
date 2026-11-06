class Solution {
    /**
     * @param {character[][]} grid
     * @return {number}
     */
    dfs(i, j, vis, grid, m, n){
        if(i<0||j<0||i>=m||j>=n||grid[i][j]!='1'||vis[i][j])return;
        vis[i][j]=true;
        this.dfs(i+1,j,vis,grid,m,n);
        this.dfs(i-1,j,vis,grid,m,n);
        this.dfs(i,j+1,vis,grid,m,n);
        this.dfs(i,j-1,vis,grid,m,n);
        return;
    }
    numIslands(grid) {
        let count = 0;
        const m = grid.length;
        const n = grid[0].length;
        let vis = Array.from({length:m},()=>Array(n).fill(false));
        for(let i = 0; i <m;i++){
            for(let j = 0; j<n;j++){
                if(grid[i][j]=='1'&&!vis[i][j]){
                    this.dfs(i,j,vis,grid,m,n);
                    count++;
                }
            }
        }
        return count;
    }
}
