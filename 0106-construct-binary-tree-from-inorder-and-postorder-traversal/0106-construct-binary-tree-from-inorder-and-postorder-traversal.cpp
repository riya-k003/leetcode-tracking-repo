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
unordered_map<int , int>mp;
    TreeNode* dfs(vector<int>& post , vector<int>& in , int postlast , int inStart , int inEnd){
        if(inStart > inEnd) return NULL;
    
        TreeNode* root = new TreeNode(post[postlast]);

        int rootIndx = mp[root->val];
        

        int rightsize = inEnd-rootIndx;

        root->left = dfs(post , in , postlast-rightsize-1 , inStart , rootIndx-1);
        root->right = dfs(post , in , postlast-1 , rootIndx+1 , inEnd);

        return root;
            }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i =0 ; i<inorder.size() ; i++){
            mp[inorder[i]] = i;
        }
        return dfs(postorder , inorder , postorder.size()-1 , 0 , inorder.size()-1);
        
    }
};