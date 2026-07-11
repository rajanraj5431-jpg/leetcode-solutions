class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // Find start of second half
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        ListNode* prev = nullptr;
        while (slow) {
            ListNode* nextNode = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextNode;
        }

        // Compare twin nodes
        int maxSum = 0;
        ListNode* first = head;
        ListNode* second = prev;

        while (second) {
            maxSum = max(maxSum, first->val + second->val);
            first = first->next;
            second = second->next;
        }

        return maxSum;
    }
};