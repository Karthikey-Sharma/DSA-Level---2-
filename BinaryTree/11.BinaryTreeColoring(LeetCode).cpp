// Link :- https://leetcode.com/problems/binary-tree-coloring-game/
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
    int xKaLeftSize;
    int xKaRightSize;
    
    int size(TreeNode * root , int x){
        if(root == NULL) {
            return 0;
        }
        
        int ls = size(root->left , x);
        int rs = size(root->right , x);
        
        if(root->val == x){
            xKaLeftSize = ls;
            xKaRightSize = rs;
        }
        
        int ts = ls + rs + 1;
        return ts; 
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        size(root , x);
        int sizeOfTheOtherSide = n - (xKaLeftSize + xKaRightSize + 1);
        int maxOfThree = max(sizeOfTheOtherSide , max(xKaLeftSize , xKaRightSize));
        int rest = n - maxOfThree;
        if(maxOfThree > rest) {
            return true;
        }else{
            return false;
        }
    }
};