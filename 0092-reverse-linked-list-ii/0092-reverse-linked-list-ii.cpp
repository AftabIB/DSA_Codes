/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
ListNode* reverse(ListNode* head)
{
    if(head == NULL)
        return NULL;
    
    ListNode* curr = head;
    ListNode* prev = NULL;
    ListNode* forward = NULL;

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* leftMost = NULL; 
        ListNode* rightMost = NULL;
        ListNode* curr = head;
        int counter = 0;
        while(curr!=NULL)
        {
            counter++;
            if(counter == left)
            {
                break;
            }
            leftMost = curr;
            curr=curr->next;
        }

        ListNode* rightHead = curr;

        while(curr!=NULL)
        {
            if(counter == right)
            {
                break;
            }
            counter++;
            curr=curr->next;
        }
        
        rightMost = curr->next;
        curr->next = NULL;

        rightHead = reverse(rightHead);

        if(leftMost == NULL)
        {
            head = rightHead;
        }
        else
        {
            leftMost->next=rightHead;
        }

        while(rightHead->next != NULL)
        {
            rightHead = rightHead->next;
        }
        rightHead->next = rightMost;
    return head;
    }
};