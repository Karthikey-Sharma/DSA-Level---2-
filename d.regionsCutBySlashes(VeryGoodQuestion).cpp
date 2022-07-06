class Solution {
public:
    int * parent;
    int * Rank;
    int find(int x){
        if(parent[x] == x){
            return x;
        }else {
            parent[x] = find(parent[x]);
            return parent[x];
        }
    }
    void Union(int xl , int yl){
        if(Rank[xl] < Rank[yl]){
            parent[xl] = yl;
        }else if(Rank[yl] < Rank[xl]){
            parent[yl]= xl;
        }else {
            parent[xl] = yl;
            Rank[yl]++;
        }
    }
    void unionHelper(int x , int y){
        int xl = find(x);
        int yl = find(y);
        if(xl != yl){
            Union(xl , yl);
        }
    }
    int regionsBySlashes(vector<string>& grid) {
        parent = new int[4 * grid.size() * grid.size()];
        Rank = new int[4 * grid.size() * grid.size()];
        for(int i = 0 ; i < (4 * grid.size() * grid.size()) ; i++){
            parent[i] = i;
            Rank[i] = 0;
        }
        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[i].size() ; j++){
                char ch = grid[i][j];
                int boxNumber = i * grid.size() + j;
                if(ch != '/'){
                    unionHelper(4 * boxNumber + 0 , 4 * boxNumber + 1);
                    unionHelper(4 * boxNumber + 2 , 4 * boxNumber + 3);
                }
                if(ch != '\\'){
                    unionHelper(4 * boxNumber + 3, 4 * boxNumber + 0);
                    unionHelper(4 * boxNumber + 1 , 4 * boxNumber + 2);
                }
                
                if(i > 0){
                    int upperBoxNumber = (i - 1) * grid.size() + j;
                    unionHelper(4 * upperBoxNumber + 2 , 4 * boxNumber + 0);
                }
                if(j > 0){
                    int leftBoxNumber = i * grid.size() + (j - 1);
                    unionHelper(4 * leftBoxNumber + 1 , 4 * boxNumber + 3);
                }
            }
        }
        int count = 0;
        for(int i = 0 ; i < (4 * grid.size() * grid.size()) ; i++){
            if(parent[i] == i){
                count++;
            }
        }
        return count;
    }

};