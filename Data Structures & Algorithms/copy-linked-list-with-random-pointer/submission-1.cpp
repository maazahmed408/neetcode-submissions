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
        Node* curr = head;

        map<Node* , Node*> hashmap; 

        while(curr){
        Node* newNode = new Node(curr->val);
        hashmap[curr] = newNode;
        curr = curr->next;
        }

       curr = head;
        while(curr){
            Node* copy = hashmap[curr];          // the SAME node from Pass 1 — no 'new'
            copy->next   = hashmap[curr->next];  // wire next to the copy of curr->next
            copy->random = hashmap[curr->random];
            curr = curr->next;
        }
    return hashmap[head];

    }
};
