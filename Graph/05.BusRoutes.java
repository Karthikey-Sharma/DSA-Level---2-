class Solution {
    class Pair{
        int bus;
        int csf;  // countSoFar
        Pair(int bus , int csf) {
            this.bus = bus;
            this.csf = csf;
        }
    }
    public int numBusesToDestination(int[][] routes, int source, int target) {
        if(source == target){
            return 0;
        }
        HashMap<Integer , ArrayList<Integer>> map = new HashMap<>();
        for(int bus = 0 ; bus < routes.length ; bus++) {
            for(int stop : routes[bus]){
                if(map.containsKey(stop) == false) {
                    map.put(stop , new ArrayList<>());
                }
                map.get(stop).add(bus);
            }
        }
        
        boolean[]visited = new boolean[routes.length];
        ArrayDeque<Pair> queue = new ArrayDeque<>();
        for(int sourceBuses : map.get(source)){
            queue.add(new Pair(sourceBuses , 1));
        }
        while(queue.size() > 0) {
            // remove mark* work addNeighbour
            // remove
            Pair front = queue.remove();
            
            // mark*
            if(visited[front.bus] == true) {
                continue;
            }
            visited[front.bus] = true;
            // word
            for(int destinations : routes[front.bus]){
                if(destinations == target) {
                    return front.csf;
                }
            }
            
            // addNeighbour
            for(int stops : routes[front.bus]){
                for(int busesAtThatStop : map.get(stops)){
                    if(visited[busesAtThatStop] == false){
                        queue.add(new Pair(busesAtThatStop ,front.csf + 1));
                    }
                }
            }
            
        }
        return -1;
    }
    
}