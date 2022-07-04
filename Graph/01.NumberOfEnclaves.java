class Solution {
    boolean flag  = true;
    int len = 0;
    public void dfs(int r , int c , int[][] grid ,boolean[][] visited ) {
        if(r < 0 || c < 0 || r >= grid.length || c >= grid[0].length) {
            flag = false;
            return;
        }
        else if(visited[r][c] == true) {
            return;
        }
        else if(grid[r][c] == 0) {
            return;
        }
        len++;
        visited[r][c] = true;
        dfs(r - 1 , c , grid , visited ); // up
        dfs(r , c + 1 , grid , visited );// right
        dfs(r + 1 , c , grid , visited);// down
        dfs(r , c - 1 , grid , visited );// left
    }
    public int numEnclaves(int[][] grid) {
        boolean[][] visited = new boolean[grid.length][grid[0].length];
        int count = 0;
        for(int i = 0 ; i < grid.length ; i++){
            for(int j = 0 ; j < grid[i].length ; j++) {
                if(grid[i][j] == 1 && visited[i][j] == false){
                    flag = true;
                    len = 0;
                    dfs(i , j , grid , visited);
                    if(flag == true) {
                        count += len;
                    }
                }
            }
        }
        return count;
    }
}