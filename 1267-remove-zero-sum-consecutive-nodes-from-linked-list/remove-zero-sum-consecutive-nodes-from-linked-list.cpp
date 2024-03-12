// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* removeZeroSumSublists(ListNode* head) {
        
//     }
// };










// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        unordered_map<int, ListNode*> prefixSums;

        int sum = 0;
        ListNode* current = dummy;

        while (current) {
            sum += current->val;
            if (prefixSums.find(sum) != prefixSums.end()) {

                ListNode* temp = prefixSums[sum]->next;
                int tempSum = sum + temp->val;
                while (temp != current) {
                    prefixSums.erase(tempSum);
                    temp = temp->next;
                    tempSum += temp->val;
                }
                prefixSums[sum]->next = current->next;
            } else {
                prefixSums[sum] = current;
            }
            current = current->next;
        }

        return dummy->next;
    }
};