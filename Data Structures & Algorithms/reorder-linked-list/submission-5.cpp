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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = slow->next;
        slow->next = nullptr;

        ListNode* curr = second;
        ListNode* prev = nullptr;

        while(curr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        //prev is new head & head;

        ListNode dummy(0);
        ListNode* tail = &dummy;

        bool flip = true;

        while(head && prev){
            if(flip){
                tail->next = head;
                head= head->next;
            }else{
                tail->next = prev;
                prev = prev->next;
            }
            tail = tail->next;
            flip = !flip;
        } 

        if(head) tail->next = head;
        if(prev) tail->next = prev;

        

    }
};
