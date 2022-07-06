class Solution {
    static int[] parent;
    static int[] rank;
    public int find(int x){
        if(parent[x] == x) {
            return x;
        }else {
            parent[x] = find(parent[x]);
            return parent[x];
        }
    }
    public void union(int x , int y){
        if(rank[x] < rank[y]){
            parent[x] = y;
        }
        else if(rank[y] < rank[x]){
            parent[y] = x;
        }else {
            parent[x] = y;
            rank[y]++;
        }
    }
    public int[] findRedundantConnection(int[][] edges) {
        parent = new int[edges.length + 1];
        rank =   new int[edges.length + 1];
        for(int i = 0 ; i < edges.length ; i++){
            parent[i] = i;
            rank[i] = 0;
        }
        for(int[] edge : edges) {
            int x = edge[0];
            int y = edge[1];
            
            int xKaLead = find(x);
            int yKaLead = find(y);
            if(xKaLead != yKaLead){
                union(xKaLead , yKaLead);
            }else {
                return edge;
            }
        }
        return null;
    }
}