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
    ListNode* swapPairs(ListNode* head) {
        ListNode* temp = new ListNode(0);
        temp -> next = head;
        ListNode* prev = temp;
        ListNode* curr = head;
        while(curr != NULL && curr->next != NULL)
        {
            ListNode* nextNode = curr->next;
            ListNode* nextToNextNode = curr->next->next;
            nextNode->next = curr;
            curr->next = nextToNextNode;
            prev->next = nextNode;
            prev = curr;
            curr = nextToNextNode;
        }
        return temp ->next;

    }
};