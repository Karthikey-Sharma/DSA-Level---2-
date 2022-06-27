// Link :- https://leetcode.com/problems/recover-binary-search-tree/
class Solution {
public:
    void recoverTree(TreeNode* root) {
      if(root == NULL) return;
        TreeNode * prev = NULL;
        TreeNode * curr = root;
        TreeNode * n1 = NULL;
        TreeNode * n2 = NULL;
        while(curr != NULL) {
            if(curr->left == NULL) {
                // print
                if(prev != NULL) {
                    if(curr->val < prev->val) {
                        if(n1 == NULL) { // checking if its first time
                            n1 = prev;
                            n2 = curr;
                        }else{
                            n2 = curr;
                        }
                    }
                }
                prev = curr;
                curr = curr->right;
            }else{
                TreeNode * iop = curr->left;
                while(iop->right != NULL && iop->right != curr) {
                    iop = iop->right;
                }
                if(iop->right == NULL) {
                    iop->right = curr;
                    curr = curr -> left;
                }else{
                // print
                if(prev != NULL) {
                    if(curr->val < prev->val) {
                        if(n1 == NULL) { // checking if its first time
                            n1 = prev;
                            n2 = curr;
                        }else{
                            n2 = curr;
                        }
                    }
                }
                prev = curr;
                    iop->right = NULL;
                    curr = curr->right;
                }
            }  
        }
        int temp = n1->val;
        n1->val = n2->val;
        n2->val = temp;
    }
};

//************************** Aliter :- (Alternate Solution) ******************//


class Solution {
public:
    void recoverTree(TreeNode* root) {
      if(root == NULL) return;
        TreeNode * prev = NULL;
        TreeNode * curr = root;
        TreeNode * n1 = NULL;
        TreeNode * n2 = NULL;
        TreeNode * n3 = NULL;
        TreeNode * n4 = NULL;
        int count = 0;
        while(curr != NULL) {
            if(curr->left == NULL) {
                // print
                if(prev != NULL) {
                    if(curr->val < prev->val) {
                        count++;
                        if(count == 1){
                            n1 = prev;
                            n2 = curr;
                        }else if(count == 2) {
                            n3 = prev;
                            n4 = curr;
                        }
                    }
                }
                prev = curr;
                curr = curr->right;
            }else{
                TreeNode * iop = curr->left;
                while(iop->right != NULL && iop->right != curr) {
                    iop = iop->right;
                }
                if(iop->right == NULL) {
                    iop->right = curr;
                    curr = curr -> left;
                }else{
                // print
                if(prev != NULL) {
                    if(curr->val < prev->val) {
                        count++;
                        if(count == 1){
                            n1 = prev;
                            n2 = curr;
                        }else if(count == 2) {
                            n3 = prev;
                            n4 = curr;
                        }
                    }
                }
                prev = curr;
                    iop->right = NULL;
                    curr = curr->right;
                }
            }  
        }
        if(count == 1) {
            int temp = n1->val;
            n1->val = n2->val;
            n2->val = temp;
        }else if(count == 2){
            int temp = n1->val;
            n1->val = n4->val;
            n4->val = temp;
        }
        
    }
};