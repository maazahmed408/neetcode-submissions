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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        if(curr->next == nullptr){
            return {};
        }
        int nodeLen = 1;
        int count = 1;

        while(curr){
            curr = curr->next;
            ++nodeLen;
        }

        ListNode dummy(0);
        dummy.next = head;
        curr = &dummy;

        while(count < nodeLen - n && curr){
            curr = curr->next;
            ++count;
        }


        ListNode* temp = curr->next->next ;
        curr->next->next = nullptr;
        curr->next = temp;

        return dummy.next;
    }
};
