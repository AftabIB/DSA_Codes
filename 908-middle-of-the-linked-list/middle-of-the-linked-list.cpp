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

// int getLen(ListNode* head)
// {
//     int len = 0;
//     while(head != NULL)
//     {
//         len++;
//         head = head -> next;
//     }
//     return len; 
// }


public:
    ListNode* middleNode(ListNode* head) {

        if(head == NULL || head -> next == NULL)
        {
            return head;
        }

        ListNode* fast = head -> next;
        ListNode* slow = head;

        while(fast != NULL)
        {
            fast = fast -> next;
            if(fast != NULL)
            {
                fast = fast -> next;
            }

            slow = slow -> next;
        }

        return slow;
        
    //     int len = getLen(head);
    //     int ans = len/2;

    //     ListNode* temp = head;
    //     int cnt = 0;
    //     while(cnt < ans)
    //     {
    //         temp = temp->next;
    //         cnt++;
    //     }
    //     return temp;
    }
};