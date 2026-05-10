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
        int count = 0;

        while(curr){
            count++;
            curr = curr->next;
        }

        if(count == 1 || count == 0){
           return head = nullptr;
        }

       
        cout<<count<<endl;
        int removeIndex = count - n;
        cout<<removeIndex;

        if(!removeIndex){
            return head = head->next;
        }

        curr = head;
        count = 1;

        while(count <= removeIndex){
            if(count == removeIndex){
                curr->next = curr->next->next;

            }else{
                curr = curr->next;
            }
                count++;   
        }

        return head;
    }
};
