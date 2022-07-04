class Solution {
public:
    class Pair {
        public:
        int v;
        int color;
        Pair(int v , int color){
            this->v = v;
            this->color = color;
        }
    };
    bool bfs(vector<vector<int>>& graph , int src , vector<int>& visited) {
        queue<Pair> queue;
        queue.push(Pair(src , 1));
        while(queue.size() > 0) {
            Pair front = queue.front();
            queue.pop();
            if(visited[front.v] != 0) {
                int oldColor = visited[front.v];
                int newColor = front.color;
                if(oldColor == newColor) {
                    continue;
                }else{
                    return false;
                }
            }
            visited[front.v] = front.color;
            for(int nbr : graph[front.v]){
                if(visited[nbr] == 0) {
                    queue.push(Pair(nbr , front.color * -1));
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> visited(graph.size() , 0);
        for(int i = 0 ; i < graph.size() ; i++){
            if(visited[i] == 0){
                bool isBip = bfs(graph , i , visited);
                if(!isBip) {
                    return false;
                }
            }
        }
        return true;
    }
};


// Using DFS
public boolean traverseDFS(int[][] graph, int[] visited, int v, int color){
        visited[v] = color;
        for(int nbr: graph[v]){
            if(visited[nbr] == 0){
                boolean isBip = traverseDFS(graph, visited, nbr, color * -1);
                if(isBip == false){
                    return false;
                }
            } else {
                int oc = visited[nbr];
                int nc = color * -1;
                
                if(oc != nc){
                    return false;
                }
            }
        }
        
        return true;
    }
}