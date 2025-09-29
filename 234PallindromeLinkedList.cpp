class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }

    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = reverseList(slow->next);
        ListNode* first = head;
        ListNode* copySecond = second;

        while (second) {
            if (first->val != second->val) {
                reverseList(copySecond);
                return false;
            }
            first = first->next;
            second = second->next;
        }

        reverseList(copySecond);
        return true;
    }
};
