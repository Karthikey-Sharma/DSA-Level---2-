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
    // Space - O(1) /// not even recursion stack
    // Time - O(4N) or O(N) As we are visiting node atmost 2 times only
    public List<Integer> inorderTraversal(TreeNode root) {
        
        List<Integer> retVal = new ArrayList<>();
        if(root == null) return retVal;
        
        TreeNode curr = root;
        while(curr != null) {
            if(curr.left == null){
                // Print
                retVal.add(curr.val);
                // go to right
                curr = curr.right;
            }else{ // when curr.left != null
                // see if left is processed or not(inorderPredecessor is left ka rightMost)
                TreeNode iop = curr.left;
                while(iop.right != null && iop.right != curr) {
                    iop = iop.right;
                }
                // if left is not processed
                if(iop.right == null) {
                    // inorderPredecessor.right = curr
                    iop.right = curr;
                    // and then go to left
                    curr = curr.left;
                }
                // if left is processed
                else{ // when iop.right = curr
                    // inorderPredecessor.right = null
                    iop.right = null;
                    // Print
                    retVal.add(curr.val);
                    // go to right
                    curr = curr.right;
                }
            }
        }
        return retVal;
    }
}