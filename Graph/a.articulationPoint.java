// { Driver Code Starts
    import java.util.*;
    import java.lang.*;
    import java.io.*;
    class GFG
    {
        public static void main(String[] args) throws IOException
        {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            int T = Integer.parseInt(br.readLine().trim());
            while(T-->0)
            {
                String[] s = br.readLine().trim().split(" ");
                int V = Integer.parseInt(s[0]);
                int E = Integer.parseInt(s[1]);
                ArrayList<ArrayList<Integer>>adj = new ArrayList<>();
                for(int i = 0; i < V; i++)
                    adj.add(i, new ArrayList<Integer>());
                for(int i = 0; i < E; i++){
                    String[] S = br.readLine().trim().split(" ");
                    int u = Integer.parseInt(S[0]);
                    int v = Integer.parseInt(S[1]);
                    adj.get(u).add(v);
                    adj.get(v).add(u);
                }
                Solution obj = new Solution();
                int[] ans = obj.articulationPoints(V, adj);
                for(int i: ans)
                    System.out.print(i + " ");
                System.out.println();
            }
        }
    }// } Driver Code Ends
    
    
    class Solution
    {
        public int[] articulationPoints(int V, ArrayList<ArrayList<Integer>> adj)
        {
            boolean[] visited = new boolean[V];
            int[] discovery = new int[V];
            int[] low = new int[V];
            boolean[] articulationPoints = new boolean[V];
            for(int i = 0 ; i < V ; i++){
                if(!visited[i]){
                    dfs(adj , visited , discovery , low , articulationPoints , i , -1);
                } 
            }
            int count = 0;
            for(boolean ap : articulationPoints){
                if(ap){
                    count++;
                }
            }
            if(count == 0){
                return new int[] {-1};
            }else{
                int[] res = new int[count];
                int idx = 0;
                for(int i = 0 ; i < articulationPoints.length ; i++){
                    if(articulationPoints[i] == true){
                        res[idx] = i;
                        idx++;
                    }
                }
                 return res;
            }
           
        }
        int time = 0;
        public void dfs(ArrayList<ArrayList<Integer>> adj , boolean[]visited , int[] discovery , int[] low , boolean[] articulationPoints , int u , int p){
            visited[u] = true;
            discovery[u] = low[u] = ++time;
            int child = 0;
            for(int v : adj.get(u)){
                if(v == p){ // neighbour hai par parent hai
                    continue;
                }else if(visited[v]){ // neighbour hai par visited hai(not parent)
                    low[u] =Math.min(discovery[v] , low[u]);
                }else {// unvisited neighbour
                    child++;
                    dfs(adj , visited , discovery , low , articulationPoints , v , u);
                    low[u] = Math.min(low[v] , low[u]);
                    if(p != -1 && low[v] >= discovery[u]){
                        articulationPoints[u] = true;
                    }
                }
                if(p == -1 && child > 1 ){
                    articulationPoints[u] = true;
                }
            }
            
        }
    }