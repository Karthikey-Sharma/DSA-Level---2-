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
    public int findBottomLeftValue(TreeNode root) {
        ArrayList<Integer> leftView = new ArrayList<>();
        ArrayDeque<TreeNode> q = new ArrayDeque<>();
        q.add(root);
        while(q.size() > 0){
            int levelSize = q.size();
            for(int i = 0 ; i < levelSize ; i++){
                TreeNode front = q.remove() ; // remove
                if(i == 0){ // print
                    leftView.add(front.val);
                }
                if(front.left != null){
                    q.add(front.left);
                }
                if(front.right != null){
                    q.add(front.right);
                }
            }
        }
        return leftView.get(leftView.size() - 1);
    }
}

//   ||||||   Aliter :- without using ArrayList |||||

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
    public int findBottomLeftValue(TreeNode root) {
        int ans = -1;
        ArrayDeque<TreeNode> q = new ArrayDeque<>();
        q.add(root);
        while(q.size() > 0){
            int levelSize = q.size();
            for(int i = 0 ; i < levelSize ; i++){
                TreeNode front = q.remove() ; // remove
                if(i == 0){ // print
                    ans = front.val;
                }
                if(front.left != null){
                    q.add(front.left);
                }
                if(front.right != null){
                    q.add(front.right);
                }
            }
        }
        return ans;
    }
}