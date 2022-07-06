class Solution {
    int[] parent;
    int[] rank;
    int find(int x){
        if(parent[x] == x){
            return x;
        }else {
            parent[x] = find(parent[x]);
            return parent[x];
        }
    }
    void union(int xl , int yl){// xlead and ylead
        if(rank[xl] < rank[yl]){
            parent[xl] = yl;
        }else if(rank[yl] < rank[xl]){
            parent[yl] = xl;
        }else {
            parent[xl] = yl;
            rank[yl]++;
        }
    }
    void unionHelper(int x , int y){
        int xl = find(x);
        int yl = find(y);
        if(xl != yl) {
            union(xl , yl);
        }
    }
    public int regionsBySlashes(String[] grid) {
        parent = new int[4 * grid.length * grid.length];
        rank = new int[4 * grid.length * grid.length];
        for(int i = 0 ; i < parent.length ; i++){
            parent[i] = i;
            rank[i] = 0;
        }
        for(int i = 0 ; i < grid.length ; i++){
            for(int j = 0 ; j < grid[i].length() ; j++) {
                char ch = grid[i].charAt(j);
                
                int boxNumber = i * grid.length + j;  // i * n + j // n is column 
                
                if(ch != '/') {
                    unionHelper(4 * boxNumber + 0 , 4 * boxNumber + 1);
                    unionHelper(4 * boxNumber + 2 , 4 * boxNumber + 3);
                }
                if(ch != '\\'){
                    unionHelper(4 * boxNumber + 0 , 4 * boxNumber + 3);
                    unionHelper(4 * boxNumber + 1 , 4 * boxNumber + 2);
                }
                if(i > 0) {
                    int upperBoxNumber = (i - 1) * grid.length + j;
                    unionHelper(4 * upperBoxNumber + 2 , 4 * boxNumber + 0);
                }
                if(j > 0){
                    int leftBoxNumber = i * grid.length + (j - 1);
                    unionHelper(4 * leftBoxNumber + 1 , 4 * boxNumber + 3);
                }
            }
        
        }
        int count = 0;
        for(int i = 0 ; i < parent.length ; i++) {
            if(parent[i] == i){
                count++;
            }
        }
        return count;
    }
}