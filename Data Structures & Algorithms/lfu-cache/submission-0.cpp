
class LFUCache {
    struct ListNode {
        int val;
    
        ListNode* nxt;
        ListNode* prev;
        ListNode(int v): val(v), prev(nullptr), nxt(nullptr){};
        ListNode(int v, ListNode* p, ListNode* n): val(v), prev(p), nxt(n){};
    };

    struct LinkedList{
        ListNode* left;
        ListNode* right;
        unordered_map<int, ListNode*> mp;

        LinkedList(){
            left = new ListNode(0);
            right = new ListNode(0);
            left->nxt = right;
            right->prev = left;
        }
        int popLeft(){
            int targetVal = left->nxt->val;
            pop(targetVal);
            return targetVal;
        }
        void pop(int val){
            if(mp.find(val) != mp.end()){
                ListNode* target = mp[val];
                target->nxt->prev = target->prev;
                target->prev->nxt = target->nxt;
                mp.erase(val);
                delete target;
            }

        };
        void update(int val){
            pop(val);
            pushRight(val);
        };
        int length(){
            return mp.size();
        }
        void pushRight(int val){
            ListNode* node = new ListNode(val);
            node->nxt = right;
            node->prev = right->prev;
            right->prev->nxt = node;
            right->prev = node;
            mp[val] = node;
        }
    };
public:
    unordered_map<int, int> countMp;
    unordered_map<int, int> valMp;
    unordered_map<int, LinkedList*> listMp;

    int capacity;
    int count;
    int lfuCount;

    LFUCache(int c) {
        capacity = c;
        listMp[0] = new LinkedList();
    }
    
    void counter(int key){
        int newCount = countMp[key]+1;
        listMp[newCount-1]->pop(key);
        countMp[key]++;
        if(!listMp.count(newCount)){
            listMp[newCount] = new LinkedList();
        }
        listMp[newCount]->pushRight(key);
        if(newCount-1 == lfuCount && listMp[newCount-1]->length() == 0){
            lfuCount++;
        }
    }

    int get(int key) {
        if(valMp.find(key) != valMp.end()){
            counter(key);
            return valMp[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;

        if(valMp.find(key) == valMp.end() && valMp.size() == capacity){
            int toRemove = listMp[lfuCount]->popLeft();
            valMp.erase(toRemove);
            countMp.erase(toRemove);
        }
        valMp[key] = value;
        if(countMp.find(key) == countMp.end()){
            countMp[key]=0;
            listMp[0]->pushRight(key);
            lfuCount = 0;
        }
        counter(key);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */