class Solution {
public:
    class Pair {
        public:
        int x;
        int y;
        int t;
        Pair(int x , int y , int t){
            this->x = x;
            this->y = y;
            this->t = t;
        }
    };
    
    void addNeighbour(int x , int y , int t , vector<vector<int>> & grid , vector<vector<bool>>& visited , queue<Pair>& queue){
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size()){
            return;
        }else if(visited[x][y] == true) {
            return;
        }else if(grid[x][y] == 0){
            return;
        }
        queue.push(Pair(x , y , t));
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        queue<Pair> queue;
        int fresh = 0;
        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[0].size() ; j++) {
                if(grid[i][j] == 2){
                    queue.push(Pair(i , j , 0));
                }else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        int time = 0;
        vector<vector<bool>> visited(grid.size() , vector<bool>(grid[0].size() , false));
        while(queue.size() > 0) {
            // remove mark* work addNeighbour*
            //remove
            Pair front = queue.front();
            queue.pop();
            // mark*
            if(visited[front.x][front.y] == true) {
                continue;
            }
            visited[front.x][front.y] = true;
            
            // work
            if(front.t > time) {
                time = front.t;
            }
            if(grid[front.x][front.y] == 1) {
                fresh--;
            }
            // add neighbour
            addNeighbour(front.x - 1 , front.y , front.t + 1 , grid , visited , queue);//up
            addNeighbour(front.x , front.y + 1 , front.t + 1 , grid , visited , queue );//right
            addNeighbour(front.x + 1 , front.y , front.t + 1 , grid , visited , queue);//down
            addNeighbour(front.x , front.y - 1 , front.t + 1 , grid , visited , queue);// left
            
        }
        if(fresh == 0){
            return time;
        }else{
            return -1;
        }
    }
};