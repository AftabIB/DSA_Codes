//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

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
    Node* root = newNode(stoi(ip[0]));
        
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
            currNode->left = newNode(stoi(currVal));
                
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
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:
    void search(Node *root, int x, Node* &ptr){
        if (root==nullptr) return ;
        if (root->data == x) {ptr=root; return;}
        if (root->left != nullptr) search(root->left, x, ptr);
        if (root->right != nullptr) search(root->right, x, ptr);
    }
    void whos_ur_daddy(Node *root, Node *parent, map<Node *, Node *> &mp){
        mp[root] = parent;
        if (root->left != nullptr) whos_ur_daddy(root->left, root, mp);
        if (root->right!= nullptr) whos_ur_daddy(root->right, root, mp);
        
    }
public:
    void lets_do_it(Node *root, int k, int &t, vector<int> &v){
        if (root == nullptr) return ;
        if (t==k) {v.push_back(root->data); return ;}
        t++;
        if (root->left!=nullptr) lets_do_it(root->left, k, t, v);
        if (root->right!=nullptr) lets_do_it(root->right, k, t, v);
        t--;
    }
    void lets_do_it_again(Node *root, Node *child, int k, int &t, vector<int> &v){
        if (root == nullptr){cout<<"exit"; return ;}
        if (t==k) {v.push_back(root->data); return ;}
        t++;
        if (root->left!=nullptr and root->left != child) lets_do_it_again(root->left, child, k, t, v);
        if (root->right!=nullptr and root->right != child) lets_do_it_again(root->right, child, k, t, v);
        t--;
    }
    vector<int> KDistanceNodes(Node* root, int target , int k)
    {
        vector<int> v;
        vector<Node*> a;
        Node *head = root;
        Node *ptr = root;
        search(root, target, ptr);
        int t=0;
        Node *ptr1 = ptr;
        lets_do_it(ptr1, k, t, v);
        map<Node *, Node *> mp;
        whos_ur_daddy(root, nullptr, mp);
        while(1){
            t=0;
            k--;
            if (t<=k and ptr!=root){
                lets_do_it_again(mp[ptr], ptr, k,t, v);
                ptr = mp[ptr];
            }
            else break;
        }
        sort(v.begin(), v.end());
        return v;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends