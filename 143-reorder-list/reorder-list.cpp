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
public:
    void reorderList(ListNode* head) {

        // Finding middle element of LL
        ListNode* slow = head;
        ListNode* fast = head -> next;

        while(fast != NULL)
        {
            fast = fast -> next;
            if(fast != NULL)
            {
                fast = fast -> next;
            }
            slow = slow -> next;
        }


        //Reverse the LL
        ListNode* prev = NULL;
        ListNode* forward = NULL;
        ListNode* curr = slow -> next;

        while(curr)
        {
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }
        slow->next = NULL;    

        // Merge the 2 LL
        ListNode* A = head;
        ListNode* B = prev;

        while(A && B)
        {
            ListNode* nextA = A -> next;
            ListNode* nextB = B -> next;

            A -> next = B;
            B -> next = nextA;

            A = nextA;
            B = nextB;
        }
    }
};