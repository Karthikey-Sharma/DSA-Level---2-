// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  string s;
    void traverse(int i , int j  ,vector<vector<int>>&grid , vector<vector<bool>>&visited) {
        visited[i][j] = true;
        if(i- 1 >= 0 && grid[i - 1][j] == 1 && visited[i - 1][j] == false){  // N
            s+="N";
            traverse(i - 1  , j , grid , visited);
        }
        if(j + 1 < grid[0].size() && grid[i][j + 1] == 1 && visited[i][j + 1] == false){ // R
            s+= "E";
            traverse(i , j + 1, grid , visited);
        }
        if(i + 1 < grid.size() && grid[i + 1][j] == 1 && visited[i+1][j] == false){ // S
            s += "S";
            traverse(i + 1 , j , grid ,visited);
        }
        if(j- 1 >= 0 && grid[i][j - 1] == 1 && visited[i][j - 1] == false){ // W
            s += "W";
            traverse(i  , j - 1 , grid ,visited);
        }
        s += "B"; // Backtrack
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size() , vector<bool>(grid[0].size() , false));
        set<string> set;
        for(int i = 0 ; i < grid.size() ; i++) {
            for(int j = 0 ; j < grid[0].size() ; j++) {
                if(visited[i][j] == false && grid[i][j] == 1) {
                    s = "";
                    traverse(i , j , grid , visited);
                    set.insert(s);
                }
            }
        }
        return set.size();
    }
};


// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}  // } Driver Code Ends