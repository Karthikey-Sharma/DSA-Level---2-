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
// Space - O(1) /// not even recursion stack
 // Time - O(4N) or O(N) As we are visiting node atmost 2 times only
class Solution {
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> retVal = new ArrayList<>();
        if(root == null) return retVal;
        
        TreeNode curr = root;
        while(curr != null) {
            if(curr.left == null){
                retVal.add(curr.val);
                curr = curr.right;
            }else{
                TreeNode iop = curr.left;
                while(iop.right != null && iop.right != curr) {
                    iop = iop.right;
                }
                if(iop.right == null) {
                    retVal.add(curr.val);
                    iop.right = curr;
                    curr = curr.left;
                }
                else{ 
                    iop.right = null;
                    curr = curr.right;
                }
            }
        }
        return retVal;
    }
}