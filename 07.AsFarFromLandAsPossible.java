class Solution {
    class Pair {
        int i;
        int j;
        int level;
        Pair(int i , int j , int level) {
            this.i = i;
            this.j = j;
            this.level = level;
        }
    }
     public void addNeighbour(int i , int j , int level ,  int[][]grid , boolean[][]visited , ArrayDeque<Pair>queue) {
        if(i < 0 || j < 0 || i >= grid.length || j >= grid[0].length || visited[i][j] == true) {
            return;
        }
        queue.add(new Pair(i , j , level ));
    }
    public int maxDistance(int[][] grid) {
        ArrayDeque<Pair> queue = new ArrayDeque<>();
        int water = 0;
        for(int i = 0 ; i < grid.length ; i++) {
            for(int j  = 0 ; j < grid[0].length ; j++) {
                if(grid[i][j] == 1){
                    queue.add(new Pair(i , j , 0));
                }else {
                    water++;
                }
            }
        }
        if(water == (grid.length * grid[0].length) || water == 0){
            return -1;
        }
        boolean[][] visited = new boolean[grid.length][grid[0].length];
        int maxDistance = 0;
        while(queue.size() > 0){
            // remove
            Pair front = queue.remove();
            // mark
            if(visited[front.i][front.j] == true) {
                continue;
            }
            visited[front.i][front.j] = true;
            // work
            if(front.level > maxDistance) {
                maxDistance = front.level;
            }
            // add Neighbour
            addNeighbour(front.i - 1 , front.j , front.level + 1  , grid , visited , queue);
            addNeighbour(front.i , front.j + 1 , front.level + 1 ,  grid , visited , queue);
            addNeighbour(front.i + 1 , front.j , front.level + 1 ,  grid , visited , queue);
            addNeighbour(front.i , front.j - 1 ,front.level + 1 , grid , visited , queue);
        }
        
        return maxDistance;
    }
}