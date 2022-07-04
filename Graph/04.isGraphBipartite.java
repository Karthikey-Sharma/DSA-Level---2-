class Solution {
    class Pair {
        int v;
        int color;
        Pair(int v , int color){
            this.v = v;
            this.color = color;
        }
    }
    public boolean bfs(int[][] graph , int src , int[]visited){
        ArrayDeque<Pair> queue = new ArrayDeque<>();
        queue.add(new Pair(src , 1));
        while(queue.size() > 0) {
            // remove
            Pair front = queue.remove();
            // mark*
            if(visited[front.v] != 0){
                int oldColor = visited[front.v];
                int newColor = front.color;
                if(oldColor == newColor){
                    continue;
                }else{
                    return false;
                }
            }
            visited[front.v] = front.color;
            // add Neighbour
            for(int nbr : graph[front.v]){
                if(visited[nbr] == 0){
                    queue.add(new Pair(nbr , front.color * (-1)));
                }
            }
        }
        return true;
    }
    public boolean isBipartite(int[][] graph) {
        int[] visited = new int[graph.length];
        for(int i = 0 ; i < graph.length ; i++){
            if(visited[i] == 0) {
                boolean isBipartite = bfs(graph , i , visited);
                if(isBipartite == false) {
                    return false;
                }
            }
        }
        return true;
    }
}