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
    ListNode dummy(0);
    dummy.next = head;
    ListNode* groupPrev = &dummy;        // node just before the current group

    while (true) {
        // --- Step 1: find the kth node (group's last), and check k nodes exist ---
        ListNode* kth = groupPrev;
        for (int i = 0; i < k && kth; i++) kth = kth->next;
        if (!kth) break;                 // fewer than k left → leave as-is, done

        ListNode* groupStart = groupPrev->next;  // first node of this group
        ListNode* groupNext  = kth->next;        // first node of next group

        // --- Step 2: reverse just this group ---
        ListNode* prev = groupNext;      // ← the trick: tail auto-connects to next group
        ListNode* curr = groupStart;
        while (curr != groupNext) {      // stop at the boundary, not at null
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        // now prev == kth (the group's NEW head)

        // --- Step 3 & 4: stitch and advance ---
        groupPrev->next = kth;           // stitch #1: prev group → new head
        groupPrev = groupStart;          // old first node is now the group's tail
    }

    return dummy.next;          
    }
};
