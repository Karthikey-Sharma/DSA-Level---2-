class Solution {
    class Pair {
        int i;
        int j;
        int level;
        Pair(int i , int j , int level){
            this.i = i;
            this.j = j;
            this.level = level;
        }
    }
    public void addNeighbour(int i , int j , int level ,  int[][]mat , boolean[][]visited , ArrayDeque<Pair>queue) {
        if(i < 0 || j < 0 || i >= mat.length || j >= mat[0].length || visited[i][j] == true) {
            return;
        }
        queue.add(new Pair(i , j , level ));
    }
    public int[][] updateMatrix(int[][] mat) {
        boolean[][] visited = new boolean[mat.length][mat[0].length];
        ArrayDeque<Pair> queue = new ArrayDeque<>();
        for(int i = 0 ; i < mat.length ; i++) {
            for(int j = 0 ; j < mat[0].length ; j++) {
                if(mat[i][j] == 0){
                    queue.add(new Pair(i , j , 0));
                }
            }
        }
        int[][] ans = new int[mat.length][mat[0].length];
        while(queue.size() > 0) {
            // remove mark* work addNeighbour
            // remove
            Pair front = queue.remove();
            // mark*
            if(visited[front.i][front.j] == true) {
                continue;
            }
            visited[front.i][front.j] = true;
            // work
            ans[front.i][front.j] = front.level;
            // addNeighbour
            addNeighbour(front.i - 1 , front.j , front.level + 1  , mat , visited , queue);
            addNeighbour(front.i , front.j + 1 , front.level + 1 ,  mat , visited , queue);
            addNeighbour(front.i + 1 , front.j , front.level + 1 ,  mat , visited , queue);
            addNeighbour(front.i , front.j - 1 ,front.level + 1 , mat , visited , queue);
        }
        return ans;
    }
}