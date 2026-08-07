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
    bool checker(TreeNode* left , TreeNode* right){
        if(!left && !right)return true;
        if(!left || !right) return false;
        if(left->val == right->val){
            return checker(left->left , right->right) && checker(left->right , right->left);
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
       return checker(root->left , root->right);
        
    }
};