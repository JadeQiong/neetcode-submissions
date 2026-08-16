class MyCalendar {
public:
    struct TreeNode{
        int start, end;
        TreeNode* left, *right;
        TreeNode(int s, int e){
            start = s;
            end = e;
            left = nullptr;
            right = nullptr;
        }
    };
    TreeNode* root;
    MyCalendar() {
        root = nullptr;
    }
    bool insert(TreeNode* node, int start, int end){
        if(node->start >= end){
            if(!node->left) {
                node->left = new TreeNode(start, end);
                return true;
            }
            return insert(node->left, start, end);
        } else if(start >= node->end){
            if(!node->right){
                node->right = new TreeNode(start, end);
                return true;
            }
            return insert(node->right, start, end);
        }
        return false;
    }
    bool book(int startTime, int endTime) {
        if(!root) {
            root = new TreeNode(startTime, endTime);
            return true;
        }
        return insert(root, startTime, endTime); 
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */