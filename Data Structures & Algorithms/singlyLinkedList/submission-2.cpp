struct LinkedNode {
    LinkedNode* next;
    int val;
    LinkedNode(int v){val = v; next = nullptr;}
};
class LinkedList {
public:
    LinkedNode* dummyHead;
    LinkedList() {
        dummyHead = new LinkedNode(0);
    }

    int get(int index) {
        LinkedNode* cur = dummyHead;
        for(int i=0;i<index;i++){
            cur = cur->next;
            if(!cur) return -1;
        }
        cur = cur->next;
        if(!cur) return -1;
        return cur->val;
    }

    void insertHead(int val) {
        LinkedNode* node = new LinkedNode(val);
        node->next = dummyHead->next;
        dummyHead->next = node;
    }
    
    void insertTail(int val) {
        LinkedNode* cur = dummyHead;
        while(cur && cur->next){
            cur = cur->next;
        }
        cur->next = new LinkedNode(val);
    }

    bool remove(int index) {
        LinkedNode* cur = dummyHead;
        LinkedNode* prev = nullptr;
        for(int i=0;i<index;i++){
            prev = cur;
            cur = cur->next;
        }
        if(cur) {
            prev = cur;
            cur = cur->next;
        } else return false;
        if(!cur) return false;
        prev->next = cur->next;
        delete cur;
        return true;
    }

    vector<int> getValues() {
        vector<int> ans;
        LinkedNode* cur = dummyHead -> next;
        while(cur){
            ans.push_back(cur->val);
            cur = cur->next;
        }
        return ans;
    }
};
