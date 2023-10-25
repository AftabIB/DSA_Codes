//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    int findPosition(int in[], int inorderStart, int inorderEnd, int element){
        for(int i = inorderStart; i <= inorderEnd; i++){
            if(in[i] == element)
                return i;
        }
        return -1;
    }
    
    Node* solve(int in[],int pre[], int &porderIn, int inorderStart, int inorderEnd, int n){
        if(porderIn >= n || inorderStart > inorderEnd){
            return NULL;
        }
        
        //1. get root element from preorder arr
        int element = pre[porderIn++];
        
        //2. create node from the above element
        Node* root = new Node(element);
        
        //3. find the position of same root ele in inOrder arr
        int pos = findPosition(in, inorderStart, inorderEnd, element);
        
        
        //left call and right call: visualize inorder arr, we have root, so we construct tree by getting elements
        //from the left of the root and from the right of the root (ref: Inorder arr)
        root -> left = solve(in, pre, porderIn, inorderStart, pos-1, n);
        root -> right = solve(in, pre, porderIn, pos+1, inorderEnd, n);
        
        return root;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        int preOrderIndex = 0;
        Node* ans = solve(in, pre, preOrderIndex, 0, n-1, n);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends