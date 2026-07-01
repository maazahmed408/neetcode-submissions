class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head) return;
        vector<ListNode*> ds;
        for (ListNode* curr = head; curr; curr = curr->next) {
            ds.push_back(curr);
        }

        int l = 1, r = ds.size() - 1;
        ListNode* curr = head;
        bool takeFromEnd = true;

        while (l <= r) {
            if (takeFromEnd) {
                curr->next = ds[r--];
            } else {
                curr->next = ds[l++];
            }
            curr = curr->next;
            takeFromEnd = !takeFromEnd;
        }

        curr->next = nullptr;
    }
};