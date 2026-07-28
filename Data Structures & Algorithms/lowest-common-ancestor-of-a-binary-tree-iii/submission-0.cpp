/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        if(!q || !p) return nullptr;
        Node* n1 = p;
        Node* n2 = q;
        while(n1 != n2){
            n1 = n1->parent;
            if(!n1){
                n1 = q;
            }
            n2 = n2->parent;
            if(!n2){
                n2 = p;
            }
        }
        return n1;
    }
};