/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
   
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
      queue<TreeNode*>q;
      string st ="";
      if(root == NULL){
        return "#";
      }
      q.push(root);
      while(!q.empty()){
        TreeNode* temp = q.front();
    q.pop();

    if(temp){
    st += to_string(temp->val)+',';
        q.push(temp->left);
        q.push(temp->right);
    }
    else{
        st+="#,";
    }
    }
      return st;
    }

    // Decodes your encoded data to tree.

    TreeNode* deserialize(string data) {
        if(data == "#" || data.empty()){
        return nullptr;
        }
         stringstream ss(data);
        string token;

        getline(ss , token , ',');
        queue<TreeNode*>q;
       TreeNode* root = new TreeNode(stoi(token));
       q.push(root);
       int n = data.size();
       while(!q.empty()){
        TreeNode* parent = q.front();
        q.pop();

        if(!getline(ss , token , ',')) break;

        if(token != "#"){
        parent->left = new TreeNode(stoi(token));
        q.push(parent->left);
        }

         if(!getline(ss , token , ',')) break;

       if(token != "#"){
        parent->right = new TreeNode(stoi(token));
        q.push(parent->right);
        }
       
       }
       return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));