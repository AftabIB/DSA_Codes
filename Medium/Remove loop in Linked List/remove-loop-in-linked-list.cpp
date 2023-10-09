//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

bool isLoop(Node* head)
{
    if(!head) return false;
    
    Node* fast = head->next;
    Node* slow = head;
    
    while( fast != slow)
    {
        if( !fast || !fast->next ) return false;
        fast=fast->next->next;
        slow=slow->next;
    }
    
    return true;
}

int length(Node* head)
{
    int ret = 0;
    while(head)
    {
        ret++;
        head = head->next;
    }
    return ret;
}

bool notOriginal(Node *head, unordered_map<Node *, int>&myMap){
    
    while(head){
        if(myMap.find(head)==myMap.end()) return true;
        if(myMap[head] != (head->data)) return true;
        
        head=head->next;
    }
}




// } Driver Code Ends
/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/

class Solution
{
    // private:
    // int detectCycle(Node* head)
    // {
    //     if (head == NULL)
    //     {
    //         return NULL;
    //     }
        
    //     Node* slow = head;
    //     Node* fast = head;
        
    //     while(slow != NULL && fast != NULL)
    //     {
    //         fast = fast -> next;
    //         if(fast != NULL)
    //         {
    //             fast = fast -> next;
    //         }
            
    //         slow = slow -> next;
            
    //         if(slow == fast)
    //         {
    //             return slow;
    //         }
    //     }
    //     return NULL;
    // }
    
    // int getHeadNode(Node* head)
    // {
    //     if (head == NULL)
    //     {
    //         return NULL;
    //     }
        
    //     Node* temp = detectCycle(head);
    //     if(temp == NULL)
    //     {
    //         return NULL;
    //     }
        
    //     Node* slow = head;
    //     while(slow != temp)
    //     {
    //         slow = slow -> next;
    //         temp = temp -> next;
    //     }
    //     return slow;
    // }
    
    // public:
    // //Function to remove a loop in the linked list.
    // void removeLoop(Node* head)
    // {
    //     if(head == NULL)
    //     {
    //         return NULL;
    //     }
    
    //     Node *start = getHeadNode(head);
    //     if(start == NULL)
    //     {
    //         return head;
    //     }
    
    //     Node* temp = start;
    //     while (temp->next != start)
    //     {
    //         temp = temp->next;
    //     }
    //     temp->next = NULL;
    //     return head;
    // }
    public:
    void removeLoop(Node* head)
    {
        Node *slow = head, *fast = head ,*prev=NULL;
        while(fast!=NULL && fast->next!=NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
            
            if(fast==slow) break;
        }
        if(slow!=fast) return; 
    
        if(slow==head && fast==head){
            prev->next=NULL;
            return;
        }
        slow=head;
        while(slow->next!=fast->next){
             slow = slow->next;
             fast = fast->next;
        }
        fast->next = NULL;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        unordered_map<Node *, int>myMap;
        
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        myMap[head]=num;
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
            myMap[tail]=num;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        Solution ob;
        ob.removeLoop(head);
        
        if( isLoop(head) || length(head)!=n || notOriginal(head, myMap))
            cout<<"0\n";
        else
            cout<<"1\n";
    }
	return 0;
}

// } Driver Code Ends