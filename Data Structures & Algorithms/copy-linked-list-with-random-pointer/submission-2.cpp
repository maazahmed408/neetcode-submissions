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
        unordered_map<Node*,Node*> hashmap;

        Node* curr = head;
        while(curr){
            Node* copy = new Node(curr->val);
            hashmap.insert({curr,copy});
            curr = curr->next;
        }

        Node* it = head;

        while(it){
            hashmap[it]->random = hashmap[it->random];
            hashmap[it]->next = hashmap[it->next];
            it = it->next;
        }

        return hashmap[head];
    }
};
