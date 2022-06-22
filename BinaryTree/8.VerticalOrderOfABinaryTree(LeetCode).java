// link :- https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    static class Pair implements Comparable<Pair> {
        TreeNode node;
        int w; // width
        int d; // depth
        
        Pair(TreeNode node , int w , int d) {
            this.node = node ;
            this.w = w;
            this.d = d;
        }
        // this - other means increasing
        // other - this means decreasing
        
        public int compareTo(Pair other) {
            if(this.d == other.d) {
                return this.node.val - other.node.val;
            }
            else{
                return this.d - other.d;
            }
        }
        
    }
    public List<List<Integer>> verticalTraversal(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<>();
        if(root == null) return ans;
        
        Queue<Pair> queue = new LinkedList<>();
        queue.add(new Pair(root , 0 , 1));
        int lw = 0;
        int rw = 0;
        HashMap<Integer , ArrayList<Pair>> map = new HashMap<>();
        while(queue.size() > 0) {
            Pair front = queue.remove();
            
            if(front.w < lw){
                lw = front.w;
            }
            if(front.w > rw){
                rw = front.w;
            }
            
            if(map.containsKey(front.w) == false){
                map.put(front.w , new ArrayList<>());
                map.get(front.w).add(front);
            }else{
                map.get(front.w).add(front);
            }
            
            if(front.node.left != null){
                queue.add(new Pair(front.node.left , front.w - 1 , front.d + 1));
            }
            
            if(front.node.right != null) {
                queue.add(new Pair(front.node.right , front.w + 1 , front.d + 1));
            }
        }
        
        for(int i = lw ; i <= rw ; i++){
            List<Integer> partOfAns = new ArrayList<>();
            ArrayList<Pair> unsortedList = map.get(i);
            Collections.sort(unsortedList);
            for(Pair temp : unsortedList){
                partOfAns.add(temp.node.val);
            }
            ans.add(partOfAns);
        }
        
        return ans;
    }
}