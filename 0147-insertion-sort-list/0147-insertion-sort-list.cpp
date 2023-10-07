/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevSorted = head;
        ListNode* curr = head->next;

        while (curr) {
            if (curr->val < prevSorted->val) {
                ListNode* prev = &dummy;

                while (prev->next->val < curr->val)
                    prev = prev->next;

                prevSorted->next = curr->next;
                curr->next = prev->next;
                prev->next = curr;
            } else {
                prevSorted = curr;
            }

            curr = prevSorted->next;
        }

        return dummy.next;
    }
};
