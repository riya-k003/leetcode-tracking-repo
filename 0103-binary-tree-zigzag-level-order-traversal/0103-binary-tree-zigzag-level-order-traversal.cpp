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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>result;
        if(!root){
            return result;
        }
        queue<TreeNode*>q;
        q.push(root);
        int count =0;
        while(!q.empty()){
            vector<int>ans;
            int n = q.size();
            while(n--){
                TreeNode* temp = q.front();
                q.pop();
                ans.push_back(temp->val);
                
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            if(count%2 != 0){
                reverse(ans.begin() , ans.end());
            }
            result.push_back(ans);
            count++;
        }
        return result;
    }
};