class Solution {
public:
    int * parent;
    int * Rank;
    int find(int x){
        if(parent[x] == x){
            return x;
        }else{
            parent[x]= find(parent[x]);
            return parent[x];
        }
    }
    void Union(int s1l , int s2l){
        if(Rank[s1l] < Rank[s2l]){
            parent[s1l] = s2l;
        }else if(Rank[s2l] < Rank[s1l]){
            parent[s2l] = s1l;
        }else {
            parent[s2l] = s1l;
            Rank[s1l]++;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        parent = new int[edges.size() + 1];
        Rank = new int[edges.size() + 1];
        for(int i = 0 ; i < (edges.size() + 1) ; i++){
            parent[i] = i;
            Rank[i] = 0;
        }
        for(vector<int> edge : edges){
            int x = edge[0];
            int y = edge[1];
            int xLead = find(x);
            int yLead = find(y);
            if(xLead != yLead){
                Union(xLead , yLead);
            }else{
                return edge;
            }
        }
        vector<int> ans;
        return ans;
    }
};