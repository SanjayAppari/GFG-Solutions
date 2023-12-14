//{ Driver Code Starts
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

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int minTime(Node* root, int target) 
    {
        Node *targetNode = NULL;
        unordered_map<Node*,Node*>mp;
        
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            Node *p=q.front(); q.pop();
            if(p->data==target) targetNode = p;
            if(p->left){
                q.push(p->left); mp[p->left]=p;
            }
            if(p->right){
                q.push(p->right); mp[p->right]=p;
            }
        }
        
        int ans=0,i;
        unordered_map<Node*,bool>vis;
        q.push(targetNode);
        vis[targetNode]=1;
        while(!q.empty()){
            int n=q.size(),c=0;
            for(i=0;i<n;i++){
                Node *p = q.front(); q.pop();
                if(p->left && !vis[p->left]){
                    c++;
                    q.push(p->left); vis[p->left]=1;
                }
                if(p->right && !vis[p->right]){
                    c++;
                    q.push(p->right); vis[p->right]=1;
                }
                if(mp[p] && !vis[mp[p]]){
                    c++;
                    q.push(mp[p]); vis[mp[p]]=1;
                }
            }
            if(c!=0) ans++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

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