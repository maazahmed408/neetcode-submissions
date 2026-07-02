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

        if(lists.empty()){
            return nullptr;
        }

        while(lists.size() > 1)
        {   vector<ListNode*> mergedLists;
            for(int i = 0; i < lists.size(); i = i+2){
                mergedLists.push_back(mergeTwoSorted(lists[i],i+1< lists.size()?lists[i+1]:nullptr));
            }
            lists = mergedLists;
        }

        return lists[0];
    }

    ListNode* mergeTwoSorted(ListNode* list1 , ListNode* list2){
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while(list1 && list2){
            if(list1->val < list2->val){
                tail->next = list1;
                list1 = list1->next;
            }else{
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        if(list1){
            tail->next = list1;
        }
        if(list2){
            tail->next = list2;
        }

        return dummy.next;
    }
};
