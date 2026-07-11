class ListNode{
public:
    int key;
    ListNode* next;
    ListNode* prev;

    ListNode(int val){
        this->key = val;
        this->next = nullptr;
        this->prev = nullptr;
    }

    ListNode(){
        this->key = 0;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class MyHashSet {
    vector<ListNode*> hashset;
public:
    MyHashSet() {
        hashset.resize(100000);
        for(auto& bucket : hashset){
            bucket = new ListNode(0);
        }
    }
    
    void add(int key) {
        ListNode* curr = hashset[key % hashset.size()];
        while(curr->next){
            if(curr->next->key == key){
                return;
            }
            curr = curr->next;
        }
        curr->next = new ListNode(key);
    }
    
    void remove(int key) {
        ListNode* curr = hashset[key % hashset.size()];
        while(curr->next){
            if(curr->next->key == key){
                curr->next = curr->next->next;
                return;
            }
            curr = curr->next;
        }
    }
    
    bool contains(int key) {
           ListNode* curr = hashset[key % hashset.size()];
        while(curr->next){
            if(curr->next->key == key){
                return true;
            }
            curr = curr->next;
        }

        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */