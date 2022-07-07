class Solution {
    int[]parent;
    int[]rank;
    public int find(int x){
        if(parent[x] == x){
            return x;
        }else{
            parent[x] = find(parent[x]);
            return parent[x];
        }
    }
    public void union(int xl , int yl){
        if(rank[xl] < rank[yl]){
            parent[xl] = yl;
        }else if(rank[yl] < rank[xl]){
            parent[yl] = xl;
        }else {
            parent[xl] = yl;
            rank[yl]++;
        }
    }
    public boolean equationsPossible(String[] equations) {
        parent = new int[26];
        rank = new int[26];
        for(int i = 0 ; i < 26 ; i++){
            parent[i] = i;
            rank[i] = 0;
        }
        for(String equation : equations){
            if(equation.charAt(1) == '=' ){
                int op1 = equation.charAt(0) - 'a';
                int op2 = equation.charAt(3) - 'a';
                int l1 = find(op1);
                int l2 = find(op2);
                if(l1 != l2){
                    union(l1 , l2);
                }
            }
        }
        for(String equation : equations) {
            if(equation.charAt(1) == '!'){
                int op1 = equation.charAt(0) - 'a';
                int op2 = equation.charAt(3) - 'a';
                int l1 = find(op1);
                int l2 = find(op2);
                if(l1 == l2){
                    return false;
                } else {
                    continue;
                }
            }
        }
        return true;
    }
}