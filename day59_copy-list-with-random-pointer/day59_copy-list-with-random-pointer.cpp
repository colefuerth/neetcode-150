/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        using namespace std;
        if (head == nullptr) return nullptr;
        vector<Node*> original;
        vector<Node*> unoriginal;
        uint x;
        vector<Node*>::iterator it;
        for (Node* n = head; n != nullptr; n = n->next) {
            original.push_back(n);
            unoriginal.push_back(new Node(n->val));
        }
        x = original.size() - 1;
        for (auto i = 0; i < x; ++i) {
            unoriginal[i]->next = unoriginal[i+1];
            it = find(original.begin(), original.end(), original[i]->random);
            unoriginal[i]->random = (it == original.end()) ? nullptr : unoriginal[distance(original.begin(), it)];
        }
        it = find(original.begin(), original.end(), original.back()->random);
        unoriginal.back()->random = (it == original.end()) ? nullptr : unoriginal[distance(original.begin(), it)];
        return unoriginal[0];
    }
};
