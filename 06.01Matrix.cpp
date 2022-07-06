class Solution {
public:
    class Pair {
        public:
        int i ;
        int j;
        int level;
        Pair(int i , int j , int level) {
            this->i = i;
            this->j = j;
            this->level = level;
        }
    };
    void addNeighbour(int i , int j , int level , vector<vector<int>>&mat , vector<vector<bool>>&visited , queue<Pair>&queue) {
        if(i < 0 || j < 0 || i >= mat.size() || j >= mat[0].size() || visited[i][j] == true) {
            return;
        }
        queue.push(Pair(i , j , level ));
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<Pair> queue;
        vector<vector<int>> ans(mat.size() , vector<int>(mat[0].size()));
        for(int i = 0 ; i < mat.size() ; i++) {
            for(int j = 0 ; j < mat[0].size() ; j++) {
                if(mat[i][j] == 0){
                    queue.push(Pair(i , j , 0));
                }
            }
        }
        vector<vector<bool>>visited(mat.size() , vector<bool>(mat[0].size() , false));
        while(queue.size() > 0){
            // remove mark* work addNeighbour
            Pair front = queue.front();
            queue.pop();
            // mark*
            if(visited[front.i][front.j] == true) {
                continue;
            }
            visited[front.i][front.j] = true;
            // work
            ans[front.i][front.j] = front.level;
            //add neighbour
            addNeighbour(front.i - 1 , front.j , front.level + 1  , mat , visited , queue);
            addNeighbour(front.i , front.j + 1 , front.level + 1 ,  mat , visited , queue);
            addNeighbour(front.i + 1 , front.j , front.level + 1 ,  mat , visited , queue);
            addNeighbour(front.i , front.j - 1 ,front.level + 1 , mat , visited , queue);
            
        }
        return ans;
    }
};