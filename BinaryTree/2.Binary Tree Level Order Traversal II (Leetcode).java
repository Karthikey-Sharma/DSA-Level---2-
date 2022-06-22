// Link -https://leetcode.com/problems/binary-tree-level-order-traversal/
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
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<>();
        if(root == null) {
            return ans;
        }
        List<Integer> partialAns = new ArrayList<>();
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        q.add(null);
        Stack<List<Integer>> st = new Stack<>();
        while(q.size() > 0) {
            TreeNode front = q.remove();// remove
            if(front != null){
                partialAns.add(front.val); // print
                if(front.left != null) {
                    q.add(front.left);
                }
                if(front.right != null) {
                    q.add(front.right);
                }
            }else{
                st.push(partialAns);
                if(q.size() > 0){
                    q.add(null);
                    partialAns = new ArrayList<>();
                }
            }
        }
        while(st.size() > 0){
            List<Integer> top = st.pop();
            ans.add(top);
        }
        return ans;
    }
}