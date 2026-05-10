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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(0);
        ListNode* min = new ListNode(INT_MAX);
        ListNode* newNode = dummy;
        while(true){     
        int bestIdx = -1; 
        for(int i = 0; i<lists.size();i++){

            if (!lists[i]) continue;

            if(bestIdx == -1 || lists[i]->val < lists[bestIdx]->val){
                bestIdx = i;
            }

        }
        if (bestIdx == -1) break;

        newNode->next = lists[bestIdx];
        newNode = newNode->next;
        lists[bestIdx] = lists[bestIdx]->next;
        }

        return dummy->next;

    }
};
