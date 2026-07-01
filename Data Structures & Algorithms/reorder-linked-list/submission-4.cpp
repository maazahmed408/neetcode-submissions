class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* pivot = slow->next;

        slow->next = nullptr;

        ListNode* prev = nullptr;
        ListNode* curr = pivot;
        while(curr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        curr = head;
        ListNode* curr2 = prev;
        ListNode* dummy = new ListNode(0);

        bool toHave = true;
        while(curr && curr2){
            if(toHave){
                dummy->next = curr;
                curr = curr->next;
            }else{
                dummy->next = curr2;
                curr2 = curr2->next;
            }
            toHave = !toHave;
            dummy = dummy->next;
        }

        if(curr){
            dummy->next = curr;
        }
        if(curr2){
            dummy->next = curr2;
        }


    }
};