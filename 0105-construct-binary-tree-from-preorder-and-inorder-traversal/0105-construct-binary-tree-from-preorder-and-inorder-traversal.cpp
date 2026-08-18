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
TreeNode* dfs(vector<int>& pre , vector<int>& in , int preStart , int inStart , int inEnd){
    if(inStart > inEnd){
        return NULL;
    }

    TreeNode* root = new TreeNode(pre[preStart]);
    int rootIndx = mp[root->val];
   

    int leftSize = rootIndx-inStart;
    root->left = dfs(pre , in , preStart+1 , inStart , rootIndx-1);
    root->right = dfs(pre , in , preStart+leftSize+1 , rootIndx+1 , inEnd);
    return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i =0 ; i<inorder.size() ; i++){
            mp[inorder[i]] =i;
        }
        return dfs(preorder , inorder , 0 , 0 , inorder.size()-1);
        
    }
};