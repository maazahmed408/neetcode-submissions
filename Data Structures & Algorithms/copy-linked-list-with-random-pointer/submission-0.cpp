/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        unordered_map<Node*,Node*> hashtable;

        Node* curr = head;
        while(curr){
            Node* copy = new Node(curr->val);
            hashtable[curr] = copy;
            curr = curr->next;
        }   

        curr = head;

        while(curr){
            Node* copy = hashtable[curr];
            copy->next   = curr->next   ? hashtable[curr->next]   : nullptr;
            copy->random = curr->random ? hashtable[curr->random] : nullptr;
            curr = curr->next;
        }

        return hashtable[head];

    }
};
