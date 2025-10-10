class Solution {
public:
    ListNode* reverseLinkedList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* newHead = reverseLinkedList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }

    ListNode* getKthNode(ListNode* temp, int k) {
        k--;
        while (temp && k > 0) {
            temp = temp->next;
            k--;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode* temp = head;
        ListNode* prevLast = nullptr;

        while (temp) {
            ListNode* kthNode = getKthNode(temp, k);
            if (!kthNode) {
                if (prevLast) prevLast->next = temp;
                break;
            }

            ListNode* nextNode = kthNode->next;
            kthNode->next = nullptr;

            ListNode* newHead = reverseLinkedList(temp);

            if (temp == head) {
                head = kthNode;
            } else {
                prevLast->next = kthNode;
            }

            prevLast = temp;
            temp = nextNode;
        }
        return head;
    }
};