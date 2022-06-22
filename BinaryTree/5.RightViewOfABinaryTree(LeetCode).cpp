// Link :- https://leetcode.com/problems/binary-tree-right-side-view/submissions/
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans ;
        if(root == NULL) return ans;
        
        queue<TreeNode*>q;
        q.push(root);
        while(q.size() > 0){
            int levelSize = q.size();
            for(int i = 0 ; i < levelSize ; i++){
                TreeNode * front = q.front();
                q.pop();
                
                if(i == levelSize - 1){
                    ans.push_back(front->val);
                }
                if(front->left != NULL) {
                    q.push(front->left);
                }
                if(front->right != NULL){
                    q.push(front->right);
                }
            }
        }
        return ans;
    }
};