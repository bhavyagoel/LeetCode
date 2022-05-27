// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    Node* getTarget(Node* root, int tgt) {
        if(!root) return nullptr; 
        
        if(root->data == tgt) return root;
        
        Node* left = getTarget(root->left, tgt);
        Node* right = getTarget(root->right, tgt);
        
        if(left) return left; 
        return right;
        
    }
  
    int minTime(Node* root, int tgt) 
    {
        // Your code goes here
        Node* target = getTarget(root, tgt);
        // cout<<target->data<<endl;
        
        // return 0;
        
        map<Node*, Node*> parent; 
        map<Node*, bool> visited; 
        
        queue<Node*> q; 
        q.push(root);
        parent[root] = nullptr;
        
        while(!q.empty()) {
            int n = q.size(); 
            
            while(n--){
                Node* curr = q.front(); 
                q.pop(); 
                
                if(curr->left) {
                    parent[curr->left] = curr;
                    q.push(curr->left);
                }
                
                if(curr->right) {
                    parent[curr->right] = curr; 
                    q.push(curr->right);
                }
            }
        }
        
        
        int dist = 0; 
        
        q.push(target);
        visited[target] = true;
        
        while(!q.empty()) {
            int n = q.size(); 
            dist += 1;
            while(n--){
                Node* curr = q.front(); 
                q.pop(); 
                
                if(!visited[parent[curr]] and parent[curr]) {
                    q.push(parent[curr]);
                    visited[parent[curr]] = true; 
                }
                if(!visited[curr->left] and curr->left) {
                    q.push(curr->left);
                    visited[curr->left] = true;
                }
                if(!visited[curr->right] and curr->right) {
                    q.push(curr->right);
                    visited[curr->right] = true;
                }                
            }
        }
        
        return dist-1; 
        
    }
};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends