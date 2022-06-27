/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) {
            return ans;
        }
        
        TreeNode * curr = root;
        while(curr != NULL) {
            if(curr->left == NULL) {
                ans.push_back(curr->val);
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
                    iop->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }  
        }
        return ans;
    }
};