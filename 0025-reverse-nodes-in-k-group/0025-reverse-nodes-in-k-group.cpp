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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        //base case
        if(head == NULL)
        {
            return NULL;
        }

        //reverse k nodes
        ListNode* forward = NULL;
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* temp = head;
        int cnt = 0;

        int nodeCnt = 0;
        while(temp != NULL)
        {
            temp = temp -> next;
            nodeCnt++;
        }


        if(nodeCnt >= k)
        {
            while(curr != NULL && cnt < k )
            {
                forward = curr -> next;
                curr -> next = prev;
                prev = curr;
                curr = forward;
                cnt++;
            }

            if(forward != NULL )
            {
                head -> next = reverseKGroup(forward,k);
            }

        }
        else
        {
            return head;
        }

        return prev;
    }
};