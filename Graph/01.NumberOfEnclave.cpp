class Solution {
public:
    int len = 0;
    bool flag = true;
    void dfs(int r , int c , vector<vector<int>>& grid , vector<vector<bool>>& visited) {
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size()){
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
    int numEnclaves(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size() , vector<bool>(grid[0].size()));
        int count = 0;
        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[0].size() ; j++) {
                if(visited[i][j] == false && grid[i][j] == 1){
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
};