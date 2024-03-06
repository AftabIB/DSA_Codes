/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
    
    //Approach 1 : visited node
            // if(head == NULL || head -> next == NULL)
            // {
            //     return false;
            // }

            // map<ListNode*,bool> visited;

            // ListNode* temp = head;
            // while(temp != NULL)
            // {
            //     if(visited[temp] == true)
            //     {
            //         return true;
            //     }
            //     visited[temp] = true;
            //     temp = temp -> next;
            // }
            // return false;

    //Approach 2 : fast and slow pointer

        if(head == NULL || head -> next == NULL)
        {
            return false;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast -> next)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
            if(fast == slow)
            {
                return true;
            }
        }
        return false;
    }
};