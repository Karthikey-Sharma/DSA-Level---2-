// Link :- https://leetcode.com/problems/recover-binary-search-tree/
class Solution {
    public void recoverTree(TreeNode root) {
         //jha print kiya tha bas whi change krenge Morris traversal mein
        TreeNode prev = null;
        TreeNode curr = root;
        TreeNode n1 = null;
        TreeNode n2 = null;
        while(curr != null) {
            if(curr.left == null){
                //print
                if(prev != null) {
                    if(curr.val < prev.val) {
                        if(n1 == null) {// checking if its first time
                            n1 = prev;
                            n2 = curr;
                        }else {
                            n2 = curr;
                        }
                    }
                }
                prev = curr;
                curr = curr.right;
            }else{
                TreeNode iop = curr.left;
                while(iop.right != null && iop.right != curr) {
                    iop = iop.right;
                }
                if(iop.right == null) {
                    iop.right = curr;
                    curr = curr.left;
                }
                else{ 
                    // print
                     //print
                    if(prev != null) {
                        if(curr.val < prev.val) {
                            if(n1 == null) { // checking if its first time
                                n1 = prev;
                                n2 = curr;
                            }else {
                                n2 = curr;
                            }
                        }
                    }
                    prev = curr;
                    iop.right = null;
                    curr = curr.right;
                }
            }
        }
        int temp = n1.val;
        n1.val =n2.val;
        n2.val = temp;
    }
}

//************************** Aliter :- (Alternate Solution) ******************//

class Solution {
    public void recoverTree(TreeNode root) {
         //jha print kiya tha bas whi change krenge Morris traversal mein
        TreeNode prev = null;
        TreeNode curr = root;
        TreeNode n1 = null;
        TreeNode n2 = null;
        TreeNode n3 = null;
        TreeNode n4 = null;
        int count= 0;
        while(curr != null) {
            if(curr.left == null){
                //print
                if(prev != null) {
                    if(curr.val < prev.val) {
                       count++;
                       if(count == 1){
                          n1 = prev;
                          n2 = curr;
                       }else if(count == 2){
                           n3 = prev;
                           n4 = curr;
                       }
                    }
                }
                prev = curr;
                curr = curr.right;
            }else{
                TreeNode iop = curr.left;
                while(iop.right != null && iop.right != curr) {
                    iop = iop.right;
                }
                if(iop.right == null) {
                    iop.right = curr;
                    curr = curr.left;
                }
                else{ 
                    // print
                    if(prev != null) {
                        if(curr.val < prev.val) {
                           count++;
                           if(count == 1){
                              n1 = prev;
                              n2 = curr;
                           }else if(count == 2){
                               n3 = prev;
                               n4 = curr;
                           }
                        }
                    }
                    prev = curr;
                    iop.right = null;
                    curr = curr.right;
                }
            }
        }
        if(count == 1) {
            int temp = n1.val;
            n1.val =n2.val;
            n2.val = temp;
        }else{
            int temp = n1.val;
            n1.val =n4.val;
            n4.val = temp;
        }
        
    }
}

