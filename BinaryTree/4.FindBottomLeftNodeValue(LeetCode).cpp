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
    int findBottomLeftValue(TreeNode* root) {
        vector<int> leftView;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size() > 0){
            int levelSize = q.size();
            for(int i = 0 ; i < levelSize ; i++){
                TreeNode * front = q.front();
                q.pop();// remove
                if(i == 0){
                    leftView.push_back(front->val); /// print
                }
                //ADD
                if(front->left != NULL){
                    q.push(front->left);
                }
                if(front->right != NULL){
                    q.push(front->right);
                }
            }
        }
        return leftView[leftView.size() - 1];
    }
};

/// ALITER :-  WIthout using vector 



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
    int findBottomLeftValue(TreeNode* root) {
        int ans = -1;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size() > 0){
            int levelSize = q.size();
            for(int i = 0 ; i < levelSize ; i++){
                TreeNode * front = q.front();
                q.pop();// remove
                if(i == 0){
                    ans = front->val; /// print
                }
                //ADD
                if(front->left != NULL){
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

