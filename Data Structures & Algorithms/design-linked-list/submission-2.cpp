struct LinkedNode {
    LinkedNode* prev, *next;
    int val;
    LinkedNode(int v){
        val = v;
        prev = nullptr;
        next = nullptr;
    }
};
class MyLinkedList {
public:
    LinkedNode* head;
    LinkedNode* tail;
    MyLinkedList() {
        head = new LinkedNode(-1);
        tail = new LinkedNode(-1);
        head->next = tail;
        tail->prev = head;      
    }
    
    void Print(){
        LinkedNode* cur = head;
        while(cur){
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }

    int get(int index) {
        LinkedNode* cur = head;
        index++;
        while(index){
            if(cur){
                cur = cur->next;
            }
            index--;
        }
        if(!cur) return -1;
        Print();
        return cur->val;
    }
    
    void addAtHead(int val) {
        LinkedNode* node = new LinkedNode(val);
        node->next = head->next;
        if(head->next)
            head->next->prev = node;
        head->next = node;
        node->prev = head;
        Print();
    }
    
    void addAtTail(int val) {
        LinkedNode* node = new LinkedNode(val);
        node->next = tail;
        if(tail->prev)
        tail->prev->next = node;
        node->prev = tail->prev;
        tail->prev = node;
        Print();
    }
    
    void addAtIndex(int index, int val) {
    LinkedNode* cur = head;
    LinkedNode* node = new LinkedNode(val);
    while(index){
        if(cur) cur = cur->next;
        index--;
    }
    if(!cur) return;
    LinkedNode* nextNode = cur->next;  // ✅ save next first
    node->next = nextNode;
    node->prev = cur;
    cur->next = node;
    if(nextNode)                        // ✅ safety check
        nextNode->prev = node;
        Print();
    }
    
    void deleteAtIndex(int index) {
        LinkedNode* cur = head;
        index++;
        while(index){
            if(cur) cur = cur->next;
            index--;
        }
        if(cur && cur->prev && cur->next){
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            delete cur;
            Print();
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */