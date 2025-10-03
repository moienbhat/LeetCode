/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* findNthNode(ListNode* temp, int k) {
        int cnt = 1;
        while (temp != nullptr) {
            if (cnt == k) return temp;
            cnt++;
            temp = temp->next;
        }
        return temp;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0) return head;

        ListNode* tail = head;
        int len = 1;
        while (tail->next) {
            tail = tail->next;
            len++;
        }

        k %= len;
        if (k == 0) return head;

        tail->next = head;
        ListNode* newLastNode = findNthNode(head, len - k);
        head = newLastNode->next;
        newLastNode->next = nullptr;

        return head;
    }
};