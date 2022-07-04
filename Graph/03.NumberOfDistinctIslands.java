//

import java.util.*;
import java.io.*;

// Position this line where user code will be pasted.

class GFG {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T-- > 0) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            int[][] grid = new int[n][m];

            for (int i = 0; i < n; i++) {

                for (int j = 0; j < m; j++) {
                    grid[i][j] = sc.nextInt();
                }
            }

            Solution ob = new Solution();
            int ans = ob.countDistinctIslands(grid);
            System.out.println(ans);
        }
    }
}// } Driver Code Ends


// User function Template for Java

class Solution {
    
    void traverse(int i , int j , int[][]grid , boolean[][] visited ,   StringBuilder s){
        visited[i][j] = true;
        if(i- 1 >= 0 && grid[i - 1][j] == 1 && visited[i - 1][j] == false){  // N
            s.append("N");
            traverse(i - 1  , j , grid , visited, s);
        }
        if(j + 1 < grid[0].length && grid[i][j + 1] == 1 && visited[i][j + 1] == false){ // R
            s.append("E");
            traverse(i , j + 1, grid , visited,s);
        }
        if(i + 1 < grid.length && grid[i + 1][j] == 1 && visited[i+1][j] == false){ // S
            s.append("S");
            traverse(i + 1 , j , grid ,visited, s);
        }
        if(j- 1 >= 0 && grid[i][j - 1] == 1 && visited[i][j - 1] == false){ // W
            s.append("W");
            traverse(i  , j - 1 , grid ,visited, s);
        }
        s.append("B"); // Backtrack
    }
    int countDistinctIslands(int[][] grid) {
        HashSet<String> unique = new HashSet<>();
        boolean[][] visited = new boolean[grid.length][grid[0].length];
        for(int i = 0 ; i < grid.length ; i++) {
            for(int j = 0 ; j < grid[i].length ; j++){
                if(visited[i][j] == false && grid[i][j] == 1){
                    StringBuilder s = new StringBuilder();
                    traverse(i , j , grid , visited , s);
                    unique.add(s.toString());
                }
            }
        }
        return unique.size();
    }
    
    
}
