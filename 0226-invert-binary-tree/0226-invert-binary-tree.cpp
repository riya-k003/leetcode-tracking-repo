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
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*>q;
        if(!root)return root;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            while(n--){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left || temp->right){
                swap(temp->left , temp->right);
            }
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }  
            } 
        }
        return root;
    }
};