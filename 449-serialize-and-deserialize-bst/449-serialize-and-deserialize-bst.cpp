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
        string res = "";
        queue<TreeNode*> q; 
        q.push(root); 
        
        while(!q.empty()) {
            int n = q.size(); 
            while(n--){
                TreeNode* curr = q.front(); 
                q.pop(); 
                if(curr){
                    res += to_string(curr->val);
                    res += ',';

                    q.push(curr->left); 
                    q.push(curr->right);
                }
                else{
                    res += "null,";
                }
            }
            
            
        }
        return res; 
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<TreeNode*> q; 
        string curr = "";
        int i = 0; 
        while(data[i] != ',') curr += data[i++];
        TreeNode* root;
        if(curr.size() and curr != "null") {
            root = new TreeNode(stoi(curr));
            q.push(root);
        }
        else {
            root = nullptr;
            return root;
        }
        
        i+=1; 
        while(!q.empty()) {
            int n = q.size(); 
            while(n--){
                TreeNode* here = q.front(); 
                q.pop(); 
                
                curr = "";
                while(data[i] != ',') curr += data[i++];
                if(curr.size() and curr!="null") {
                    here->left = new TreeNode(stoi(curr));
                    q.push(here->left);
                }else here->left = nullptr; 
                i += 1; 
                
                curr = "";
                while(data[i] != ',') curr += data[i++];
                if(curr.size() and curr != "null") {
                    here->right = new TreeNode(stoi(curr));
                    q.push(here->right);
                }else here->right = nullptr; 
                i += 1; 
            }
        }
        
        return root; 
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;