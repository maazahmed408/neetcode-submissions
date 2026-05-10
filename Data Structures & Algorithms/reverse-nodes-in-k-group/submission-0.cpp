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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        //base call
        if(!head){
            return NULL;
        }
        ListNode* temp = head;
        int group = 0;
        while (temp != nullptr && group < k) {
            temp = temp->next;
            group++;
        }

        if(group < k ){
            return head;
        }

        ListNode* next = nullptr;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        int count = 0;

        while(curr && count<k){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        head->next = reverseKGroup(next,k);

        return prev;
    }
};
