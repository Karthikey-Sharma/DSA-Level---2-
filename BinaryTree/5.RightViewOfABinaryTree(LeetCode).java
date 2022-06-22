// Link :- https://leetcode.com/problems/binary-tree-right-side-view/submissions/
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
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> ans = new ArrayList<>();
        if(root == null) return ans;
        ArrayDeque<TreeNode> queue = new ArrayDeque<>();
        queue.add(root);
        while(queue.size() > 0){
            int levelSize = queue.size();
            for(int i = 0 ; i < levelSize ; i++){
                TreeNode front = queue.remove(); // remove
                if(i == levelSize - 1){
                    ans.add(front.val); // print
                }
                // ADD
                if(front.left != null) {
                    queue.add(front.left);
                }
                if(front.right != null) {
                    queue.add(front.right);
                }
            }
        }
        return ans;
    }
}