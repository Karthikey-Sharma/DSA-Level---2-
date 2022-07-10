// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    int count = 0;
    int time = 0;
    void dfs(vector<int> adj[] , vector<bool>& visited , vector<int>& discovery , vector<int>& low , vector<bool>& articulationPoints , int src , int parent){
        visited[src] = true;
        discovery[src] = low[src] = ++time;
        int child = 0;
        for(int v : adj[src]){
            if(v == parent){ // neighbour parent hai
                continue;
            }else if(visited[v]){ // visited neighour (not parent)
                low[src] = min(discovery[v] , low[src]);
            }else { // unvisited neigbour
                child++;
                dfs(adj , visited , discovery , low , articulationPoints , v , src) ;
                low[src] = min(low[v] , low[src]);
                
                if(parent != -1 && low[v] >= discovery[src]){
                    articulationPoints[src] = true;
                }
            }
        }
        if(parent == -1 && child > 1) {
            articulationPoints[src] = true;
        }
    }
    int doctorStrange(int N, int M, vector<vector<int>> & graph)
    {
        vector<bool> visited(N , false);
        vector<int> discovery(N + 1);
        vector<int> low(N + 1);
        vector<int> adj[N + 1];
        vector<bool> articulationPoints(N + 1 , false);
        for(int i = 0 ; i < M ; i++) {
            adj[graph[i][0]].push_back(graph[i][1]);
            adj[graph[i][1]].push_back(graph[i][0]);
        }
        for(int i = 0 ; i < N ; i++) {
            if(!visited[i]){
                dfs(adj , visited , discovery , low , articulationPoints , i , -1);
            }
        }
        
        int count = 0;
        for(bool aps : articulationPoints){
            if(aps){
                count++;
            }
        }
        return count;
    }
};


// { Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,i;
        cin>>n>>m;
        vector<vector<int>> g(n+1);
        for(i=0;i<m;i++)
        {
            int a,b;cin>>a>>b;
            g[i].push_back(a);
            g[i].push_back(b);
        }
        Solution ob;
        int ans = ob.doctorStrange(n, m, g);
        cout<<ans<<endl;
    }
	return 0;
}  // } Driver Code Ends