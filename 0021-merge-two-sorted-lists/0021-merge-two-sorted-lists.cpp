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
// class Solution {
// private:
// ListNode* solve(ListNode* list1, ListNode* list2)
// {
//     if(list1->next == NULL)
//     {
//         list1->next = list2;
//         return list1;
//     }
//     ListNode* curr1 = list1;
//     ListNode* next1 = curr1->next;
//     ListNode* curr2 = list2;
//     ListNode* next2 = curr2->next;

//     while(curr2 != NULL && next1 != NULL)
//     {
//         if((curr2->val >= curr1->val)&&(curr2->val <= next1->val))
//         {
//             //adding node to list
//             curr1->next = curr2;
//             next2 = curr2->next;
//             curr2->next = next1;
//             //updating pointer
//             curr1 = curr2;
//             curr2 = next2;
//         }
//         else
//         {
//             curr1 = next1;
//             next1 = next1->next;

//             if(next1 == NULL)
//             {
//                 curr1->next = curr2;
//                 return list1;
//             }
//         }
//     }
//     return list1;
// }
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         if(list1 == NULL)
//             return list2;
        
//         if(list2 == NULL)
//             return list1;

//         if(list1->val <= list2->val)
//         {
//             return solve(list1,list2);
//         }
//         else
//         {
//             return solve(list2,list1);
//         }
//     }
// };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL){
            return list2;
        }

        if(list2 == NULL){
            return list1;
        }

        if(list1 -> val > list2 -> val){
            swap(list1,list2);
        }
        

        ListNode* res = list1;  // remeber the head of ll
        while(list1 != NULL && list2 != NULL){
            ListNode* temp = NULL;
            while(list1 != NULL && list1 -> val <= list2 -> val){
                temp = list1;
                list1 = list1 -> next;
            }
            temp -> next = list2;   // break old connection and build a new
            swap(list1,list2);
        }
        return res;
    }
};