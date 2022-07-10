// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
    int res = 0;
    int time = 0;
    void dfs(vector<int> adj[] , vector<bool>& visited , vector<int>& discovery , vector<int>& low , int c , int d , int src , int parent){
        visited[src] = true;
        discovery[src] = low[src] = ++time;
        for(int v : adj[src]){
            if(v == parent){ // neighbour parent hai
                continue;
            }else if(visited[v]){ // visited neighour (not parent)
                low[src] = min(discovery[v] , low[src]);
            }else { // unvisited neigbour
                dfs(adj , visited , discovery , low , c , d , v , src) ;
                low[src] = min(low[v] , low[src]);
                if(low[v] > discovery[src]){
                    if((src == c && v == d)|| (src == d && v == c)){
                        res = 1;
                    }
                }
            }
        }
    }
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        vector<bool>visited(V , false);
        vector<int>discovery(V , 0);
        vector<int>low(V , 0);
        for(int i = 0 ; i < V ; i++){
            if(!visited[i]){
                dfs(adj , visited , discovery , low , c , d , i , -1); 
            }
        }
        return res;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

  // } Driver Code Ends