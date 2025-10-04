class Solution {
public:
    void insertCopyInBetween(Node* head) {
        Node* temp = head;
        while (temp != NULL) {
            Node* nextElement = temp->next;
            Node* copy = new Node(temp->val);

            temp->next = copy;
            copy->next = nextElement;

            temp = nextElement;
        }
    }

    void connectRandomPointers(Node* head) {
        Node* temp = head;
        while (temp != NULL) {
            Node* copyNode = temp->next;
            if (temp->random) {
                copyNode->random = temp->random->next;
            }
            temp = temp->next->next;
        }
    }

    Node* getDeepCopyList(Node* head) {
        Node* dummyNode = new Node(-1);
        Node* res = dummyNode;
        Node* temp = head;

        while (temp != NULL) {
            res->next = temp->next;
            res = res->next;

            temp->next = temp->next->next;  // restore original
            temp = temp->next;
        }
        return dummyNode->next;
    }

    Node* copyRandomList(Node* head) {
        if (!head) return NULL;
        insertCopyInBetween(head);
        connectRandomPointers(head);
        return getDeepCopyList(head);
    }
};
