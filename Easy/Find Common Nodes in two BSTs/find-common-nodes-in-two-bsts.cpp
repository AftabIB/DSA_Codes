//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends


class Solution
{
    private:
    //do inorder traversal which has input root and map of int type
    void inorder(Node *root,map<int,int>&m)
    {
        if(!root)
        {
            return;
        }
        
        //map is used to check frequency of nodes 
        inorder(root->left,m);
        m[root->data]++;            //increases the frequency of nodes in map 
        inorder(root->right,m);
    }
    
    //Function to find the nodes that are common in both BST. 
    void commonNodes(Node *root,map<int,int> &nodeFreq, vector<int> &ans)
    {
        if(!root)
        {
            return;
        }
        //check if nodes frequency is greater thn zero, if yes store it in nas and decrement the frequency
        if(nodeFreq[root->data] > 0)
        {
            ans.push_back(root->data);
            nodeFreq[root->data]--;     //decreasing the frequency
        }
        
        //do for left tree
        commonNodes(root->left,nodeFreq,ans);
        //do for right tree
        commonNodes(root->right,nodeFreq,ans);
        
    }
    public:
    vector <int> findCommon(Node *root1, Node *root2)
    {
        vector<int> ans;
        map<int,int> nodeFreq;
        inorder(root1,nodeFreq);
        commonNodes(root2,nodeFreq,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};




//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root1 = buildTree(s);

        getline(cin,s);
        Node* root2 = buildTree(s);
        Solution ob;
        vector <int> res = ob.findCommon(root1, root2);
        for (int i : res)
            cout << i << " ";
        cout<< endl;
    }

	return 1;
}
// } Driver Code Ends