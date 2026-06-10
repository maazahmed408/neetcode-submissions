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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode output(0);
        ListNode* tail = &output;
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        int carryover = 0;

        while(curr1 || curr2 || carryover){
            int digit1 = curr1 ? curr1->val : 0 ;
            int digit2 = curr2 ? curr2->val : 0 ;
            int sum = digit1 + digit2 + carryover;
            carryover = sum/10; //1 // 0
            tail->next = new ListNode(sum%10); //8 // 1
            tail = tail->next;
            curr1 = curr1 ? curr1->next: nullptr;
            curr2 = curr2 ? curr2->next:nullptr;        
            }

        return output.next;
        
    }
};
