class LRUCache {
private:
    struct Node{
        int key , val;
        Node* next;
        Node* prev;
        Node(int k , int v) : key(k),val(v),next(nullptr),prev(nullptr){}
    };
    int cap;
    Node* head;
    Node* tail;
    unordered_map<int , Node*> hashmap;

public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;    
    }
    
    int get(int key) {
        if(hashmap.find(key) != hashmap.end()){
        removeNode(hashmap[key]);
        addFront(hashmap[key]);
            return hashmap[key]->val;
        }

        return -1;

    }
    
    void put(int key, int value) {
        if(hashmap.find(key) != hashmap.end()){
            hashmap[key]->val = value;
            removeNode(hashmap[key]);
            addFront(hashmap[key]);
        }else{
            Node* newNode = new Node(key,value);
            addFront(newNode);
            hashmap[key] = newNode;         
        }
        //condition for overcapacity
        if(hashmap.size() > cap){
            hashmap.erase(tail->prev->key);
            removeNode(tail->prev);
        }
    }

    void removeNode(Node* toRemove){
        toRemove->prev->next = toRemove->next;
        toRemove->next->prev = toRemove->prev;
    }

    void addFront(Node* toAdd){
        Node* temp = head->next;
        head->next = toAdd;
        toAdd->prev = head;
        toAdd->next = temp;
        temp->prev = toAdd;
    }
};
