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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        queue<pair<TreeNode* , long long>>q;
        q.push({root , 0});
        long long maxi =0;
        while(!q.empty()){
            int n = q.size();
          long long first = q.front().second;
          long long last = first;
            while(n--){
               auto [node , index] = q.front();
                q.pop();

                index -= first;
                last = index;

                if(node->left){
                    q.push({node->left , 2*index+1});
                }
                if(node->right){
                    q.push({node->right , 2*index+2});
                }

            }
               maxi = max(maxi , last+1);
        }
        return maxi;
        
    }
};