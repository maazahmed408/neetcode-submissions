struct ListNode{
    int val;
    int key;
    ListNode* next;

    ListNode (int _key=-1,int _val=-1) : key(_key),val(_val),next(nullptr){} 
};

class MyHashMap {
private:
    vector<ListNode*> hashmap;

    int hash(int key){
        return key % hashmap.size();
    }
public:
    MyHashMap() {
        hashmap.resize(1000);
        for (auto& bucket : hashmap) {
            bucket = new ListNode(0);
        }

    }
    
    void put(int key, int value) {
        ListNode* curr = hashmap[hash(key)];

        while(curr->next){
            if(curr->next->key == key){
                curr->next->val = value;
                return;
            }
            curr = curr->next;
        }
        curr->next = new ListNode(key,value);

    }
    
    int get(int key) {
        ListNode* curr = hashmap[hash(key)]->next;

        while(curr){
            if(curr->key == key){
                return curr->val;
            }
            curr = curr->next;
        }
        return -1;
    }
    
    void remove(int key) {
        ListNode* curr = hashmap[hash(key)];

        while(curr->next){
            if(curr->next->key == key){
                curr->next = curr->next->next;
                return;
            }
            curr = curr->next;
        }
        return;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */