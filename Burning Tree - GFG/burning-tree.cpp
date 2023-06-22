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
    int result = INT_MIN ; 
    map<Node*,int> m ; 
    
    int find(Node* root,int target){
        if(!root)   return -1 ; 
        if(root->data == target){
            m[root] = 0 ; 
            return 0 ; 
        }
        int left = find(root->left,target) ; 
        if(left>=0){
            m[root] = left+1 ; 
            return left+1 ; 
        }
        int right = find(root->right,target) ; 
        if(right>=0){
            m[root] = right+1 ; 
            return right+1 ; 
        }
        return -1 ; 
    }
    
    void dfs(Node* root,int dist){
        if(!root)   return ;
        if(m.count(root))   dist = m[root] ; 
        result = max(result,dist) ; 
        dfs(root->left,dist+1) ; 
        dfs(root->right,dist+1) ; 
    }
    
    int minTime(Node* root, int target) {
        find(root,target) ; 
        dfs(root,m[root]) ; 
        return result ;
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