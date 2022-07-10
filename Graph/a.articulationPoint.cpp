// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        vector<bool> visited(V , false);
        vector<int> discovery(V);
        vector<int> low(V);
        vector<bool> articulationPoints(V , false);
        
        for(int i = 0 ; i < V ; i++) {
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
        if(count == 0){
            vector<int> ans;
            ans.push_back(-1);
            return ans;
        }else {
            vector<int> ans;
            for(int i = 0 ; i < articulationPoints.size() ; i++) {
                if(articulationPoints.at(i) == true){
                    ans.push_back(i);
                }
            }
            return ans;
        }
        
    }
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
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends