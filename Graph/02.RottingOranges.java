class Solution {
    class Pair {
        int x;
        int y;
        int t;
        Pair(int x , int y , int t) {
            this.x = x;
            this.y = y;
            this.t = t;
        }
    }
    public void addNeighbour(int x , int y , int t , int[][] grid , boolean[][] visited , ArrayDeque<Pair> queue) {
        if(x < 0 || y < 0 || x >= grid.length || y >= grid[0].length){
            return;
        }else if(visited[x][y] == true) {
            return;
        }else if(grid[x][y] == 0) {
            return;
        }
        queue.add(new Pair(x , y , t));
    }
    public int orangesRotting(int[][] grid) {
        ArrayDeque<Pair> queue = new ArrayDeque<>();
        int fresh = 0;
        int time = 0;
        for(int i = 0 ; i < grid.length ; i++) {
            for(int j = 0 ; j < grid[0].length ; j++) {
                if(grid[i][j] == 2){
                    queue.add(new Pair(i , j , 0));
                }else if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        boolean[][] visited = new boolean[grid.length][grid[0].length];
        while(queue.size() > 0) {
            // rm*w(addneighbour)*
            // remove
            Pair front = queue.remove();
            // mark
            if(visited[front.x][front.y] == true) {
                continue;
            }
            visited[front.x][front.y] = true;
            // work
            if(front.t > time) {
                time = front.t;
            }
            if(grid[front.x][front.y] == 1){
                fresh--;
            }
            // add neighbour
            addNeighbour(front.x - 1 , front.y , front.t + 1 , grid , visited , queue);//up
            addNeighbour(front.x , front.y + 1 , front.t + 1 , grid , visited , queue );//right
            addNeighbour(front.x + 1 , front.y , front.t + 1 , grid , visited , queue);//down
            addNeighbour(front.x , front.y - 1 , front.t + 1 , grid , visited , queue);// left
        }
        if(fresh == 0) {
            return time;
        }else {
            return -1;
        }
    }
}