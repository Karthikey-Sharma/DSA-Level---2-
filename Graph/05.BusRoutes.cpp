class Solution {
public:
    class Pair {
        public:
        int bus;
        int csf;// count so far
        Pair(int bus , int csf) {
            this->bus = bus;
            this->csf = csf;
        }
    };
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target){
            return 0;
        }
        map<int , vector<int>> map;  /// dest  ->  bus map
        for(int bus = 0 ; bus < routes.size() ; bus++) {
            for(int dest : routes[bus]) {
                map[dest].push_back(bus);
            }
        }
        
        queue<Pair> queue;
        vector<bool> visited(routes.size() , false);
        for(int srcPeBuses : map[source]){
            queue.push(Pair(srcPeBuses , 1));
        }
        
        while(queue.size() > 0) {
            // remove mark* work addNeighbour
            //remove
            Pair front = queue.front();
            queue.pop();
            // mark
            if(visited[front.bus] == true) {
                continue;
            }
            visited[front.bus] = true;
            
            // work
            for(int destinationsAtThatParticularBus : routes[front.bus]){
                if(destinationsAtThatParticularBus == target){
                    return front.csf;
                }
            }
            // addNeighbour
            for(int stopsInThisBus : routes[front.bus]){
                for(int busesThatTravelToThisDestination : map[stopsInThisBus]){
                    queue.push(Pair(busesThatTravelToThisDestination , front.csf + 1));
                }
            }
        }
        return -1;
    }
    
};