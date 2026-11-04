class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Advance fast pointer by n steps
        for (int i = 0; i < n; ++i) {
            fast = fast->next;
        }

        // Move both pointers until fast reaches the tail
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Remove the target node
        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete; // Clean up memory

        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};