//https://practice.geeksforgeeks.org/problems/fixed-two-nodes-of-a-bst/1
// hard Question

class Solution {
  public:
    void correctBST( struct Node* root )
    {
        if(root == NULL) return;
        Node * prev = NULL;
        Node * curr = root;
        Node * n1 = NULL;
        Node * n2 = NULL;
        while(curr != NULL) {
            if(curr->left == NULL) {
                // print
                if(prev != NULL) {
                    if(curr->data < prev->data) {
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
                Node * iop = curr->left;
                while(iop->right != NULL && iop->right != curr) {
                    iop = iop->right;
                }
                if(iop->right == NULL) {
                    iop->right = curr;
                    curr = curr -> left;
                }else{
                // print
                if(prev != NULL) {
                    if(curr->data < prev->data) {
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
        int temp = n1->data;
        n1->data = n2->data;
        n2->data = temp;
    }
};