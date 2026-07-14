/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<Node*,Node*> oldToNew;
public:
    Node* cloneGraph(Node* node) {

        // if(node == nullptr) return nullptr;

        // if(oldToNew.count(node)) return oldToNew[node];

        // Node* copyNode = new Node(node->val);

        // oldToNew[node] = copyNode;

        // for(Node* nei : node->neighbors){
        //     copyNode->neighbors.push_back(cloneGraph(nei));
        // }

        // return copyNode;

        if(node == nullptr) return nullptr;

        queue<Node*> q;
        oldToNew[node] = new Node(node->val);
        q.push(node);

        while(!q.empty()){
            Node* toPop = q.front();
            q.pop();
            for(Node* nei : toPop->neighbors){
                if(!oldToNew.count(nei)){
                    oldToNew[nei] = new Node(nei->val);
                    q.push(nei); 
                }
                oldToNew[toPop]->neighbors.push_back(oldToNew[nei]);
            }
        }

        return oldToNew[node];

    }
};
