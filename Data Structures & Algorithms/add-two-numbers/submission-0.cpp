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
        ListNode* a = l1;
        ListNode* b = l2;
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        int carry = 0;

        while(a || b || carry != 0){
            int val1 = a ? a->val : 0;
            int val2 = b ? b->val : 0;

            int sum = val1 + val2 + carry;
            ListNode* newNode = new ListNode(sum%10);

            curr->next = newNode;
            carry = sum/10;
            curr = curr->next;
            a = a ? a->next : nullptr ;
            b = b ? b->next : nullptr;    
        }

        return dummy->next;

    }
};
