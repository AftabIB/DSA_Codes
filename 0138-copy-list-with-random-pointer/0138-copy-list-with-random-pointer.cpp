/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
#include <unordered_map>
class Solution {
private:
void insertAtTail(Node* &head,Node* &tail,int data)
{
	Node* temp = new Node(data);
	if(head == NULL)
	{
		head = temp;
		tail = temp;
	}
	else
	{
		tail->next = temp;
		tail = temp;
	}
}

public:
    Node* copyRandomList(Node* head) {

    //created a clone of list
    Node* cloneHead = NULL;
	Node* cloneTail = NULL;
	
	Node* temp = head;
	while(temp != NULL)
	{
		insertAtTail(cloneHead,cloneTail,temp->val);
		temp = temp->next;
	}
	
	// step 2 : create a map 
	unordered_map <Node*,Node*> oldToNewNode;

	Node* originalList = head;
	Node* cloneList = cloneHead;

	while(originalList != NULL && cloneList != NULL)
	{
		oldToNewNode[originalList] = cloneList;
		originalList = originalList->next;
		cloneList = cloneList->next;
	}

	// step 3 : set the random pointer

	originalList = head;
	cloneList = cloneHead;
	while(originalList != NULL)
	{
		cloneList -> random = oldToNewNode[originalList -> random];
		originalList = originalList->next;
		cloneList = cloneList->next;
	} 
	return cloneHead;
    }
};