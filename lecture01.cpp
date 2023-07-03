//Lecture 17
// More Linked list problems

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL)
            return NULL;

        Node* p = head;
        Node* nxt = NULL;

        
        while (p != NULL) {
            nxt = p->next;
            Node* newNode = new Node(p->val);
            p->next = newNode;
            newNode->next = nxt;
            p = nxt;
        }

        p = head;
        while (p != NULL) {
            if (p->random != NULL) {
                p->next->random = p->random->next;
            }
            p = p->next->next;
        }

        p = head;
        Node* clone = head->next;
        Node* cloneStart = clone;

        while (p != NULL && p->next != NULL) {
            nxt = p->next;
            p->next = nxt->next;
            p = nxt;
        }

        return cloneStart;
    }
};

//ans 2:
class Node {
public:
    int val;
    Node* next, random;
};

Node *copy(Node *head){
    unordered_map<Node*,Node*> hash;
    Node *ptr=head;
    while(ptr!=NULL){
        Node *copiedNode=new Node(ptr->val);
        hash[ptr]=copiedNode;
        ptr=ptr->next;
    }
    ptr=head;
    while(ptr!=NULL){
        
        Node *copied=hash[ptr];
        copied->next=hash[ptr->next];
        copied->random=hash[ptr->random];
        ptr=ptr->next;
    }
    return hash[head];
}
