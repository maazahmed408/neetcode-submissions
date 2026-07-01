class Node {
public:
    int key;
    int val;
    Node* next;
    Node* prev;

    Node() : val(0), key(0),next(nullptr), prev(nullptr) {}

    Node(int _key,int _val) : val(_val), key(_key),next(nullptr), prev(nullptr) {}
};

class LRUCache {
    Node* head;
    Node* tail;
    int cap;
    unordered_map<int,Node*> hashmap;
public:
    LRUCache(int capacity) {
        head = new Node(-1,-1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        cap = capacity;
    }
    
    int get(int key) {
        if (!hashmap.count(key)) return -1;
        removeNode(hashmap[key]);
        Node* newNode = addNode(key,hashmap[key]->val);
        hashmap[key] = newNode;

        return head->next->val;
    }
    
    void put(int key, int value) {
        
        if(hashmap.count(key)){
            removeNode(hashmap[key]);
            Node* newNode = addNode(key,value);
            hashmap[key] = newNode;
        }
       else if(hashmap.size() < cap){
            Node* newNode = addNode(key,value);
            hashmap.insert({key,newNode});
       }else{
            hashmap.erase(tail->prev->key);
            removeNode(tail->prev);
            Node* newNode = addNode(key,value);
            hashmap.insert({key,newNode});
       }
        
    }

    Node* addNode(int key , int value){
        Node* newNode = new Node(key,value);
        Node* temp = head->next;
        head->next = newNode;
        newNode->next = temp;
        newNode->prev = head;
        temp->prev = newNode;

        return newNode;
    }

    void removeNode(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
};
