class Solution {
public:
    int * parent;
    int * ranker;
    int find(int x) {
        if(parent[x] == x){
            return x;
        }else {
            parent[x] = find(parent[x]);
            return parent[x];
        }
    }
    void Union(int xl , int yl) {
        if(ranker[xl] < ranker[yl]){
            parent[xl] = yl;
        }else if(ranker[yl] < ranker[xl]){
            parent[yl] = xl;
        }else {
            parent[xl] = yl;
            ranker[yl]++;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        parent = new int[26];
        ranker = new int[26];
        for(int i = 0 ; i < 26 ; i++) {
            parent[i] = i;
            ranker[i] = 0;
        }
        for(string equation : equations) {
            if(equation[1] == '='){
                int op1 = equation[0] - 'a';
                int op2 = equation[3] - 'a';
                int l1 = find(op1);
                int l2 = find(op2);
                Union(l1 , l2);
            }
        }
        
        for(string equation : equations) {
            if(equation[1] == '!'){
                int op1 = equation[0] - 'a';
                int op2 = equation[3] - 'a';
                int l1 = find(op1);
                int l2 = find(op2);
                if(l1 == l2){
                    return false;
                }
            }
        }
        return true;
    }
};