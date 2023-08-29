//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    private:
    Node* reverse(Node *head)
    {
        if(head == NULL || head -> next == NULL)
        {
            return head;
        }
        
        Node* forward = NULL;
        Node* curr = head;
        Node* prev = NULL;
        
        while(curr != NULL)
        {
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    
    
    public:
    Node *compute(Node *head)
    {
        if(head == NULL || head -> next == NULL)
        {
            return head;
        }
        
        head = reverse(head);
        Node* temp = head;
        
        while(temp->next != NULL)
        {
            if(temp->data > temp -> next -> data)
            {
                temp -> next = temp -> next -> next;
            }
            else
            {
                temp = temp -> next;
            }
        }
        
        Node* ans = reverse(head);
        return ans;
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends