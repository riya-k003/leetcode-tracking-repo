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
    int countNodes(TreeNode* root) {
        if(!root)return 0;
int cnt_left =0;
int cnt_right =0;
TreeNode* temp = root;
      while(temp){
        cnt_left++;
        temp = temp->left;
      }
      temp = root;
      while(temp){
        cnt_right++;
        temp = temp->right;
      }

      if(cnt_left  == cnt_right){
        return (1 << cnt_left)-1;
      }

      return 1+ countNodes(root->left) + countNodes(root->right);
        
    }
};