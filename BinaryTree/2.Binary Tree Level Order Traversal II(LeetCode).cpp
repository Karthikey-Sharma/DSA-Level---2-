// Link -https://leetcode.com/problems/binary-tree-level-order-traversal/
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        vector<int> partialAns;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(q.size() > 0){
            TreeNode * front = q.front();
            q.pop();
            if(front != NULL){
                partialAns.push_back(front->val);//print
                if(front->left != NULL){
                    q.push(front->left);
                }
                if(front->right != NULL){
                    q.push(front->right);
                }
            }
            else{
                ans.push_back(partialAns);
                if(q.size() > 0){
                    q.push(NULL);    
                    partialAns.clear();
                }
            }
        }
       
        return ans;
    }
};