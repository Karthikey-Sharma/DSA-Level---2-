// https://practice.geeksforgeeks.org/problems/inorder-successor-in-bst/1#
class Solution
{
    // returns the inorder successor of the Node x in BST (rooted at 'root')
	public Node inorderSuccessor(Node root,Node x)
    {
        Node succ = null;
        boolean found = false;
        Node curr = root;
        while(curr != null) {
            if(curr.left == null) {
                // print
                if(found == true) {
                    succ = curr;
                    break;
                }
                if(curr == x) {
                    found = true;
                }
                curr = curr.right;
            }else{
                Node iop = curr.left;
                while(iop.right != null && iop.right != curr) {
                    iop = iop.right;
                }
                if(iop.right == null) {
                    iop.right = curr;
                    curr = curr.left;
                }else{
                    // print
                     if(found == true) {
                        succ = curr;
                        break;
                    }
                    if(curr == x) {
                        found = true;
                    }
                    iop.right = null;
                    curr = curr.right;
                }
            }
            
        }
        return succ;
    }
}