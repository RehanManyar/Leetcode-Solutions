class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        // Dummy node helps us easily build the answer
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;

        int carry = 0;
        while (l1 != nullptr || l2 != nullptr || carry != 0) {

            int sum = carry;

            // Add value from l1
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            // Add value from l2
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            // Current digit
            int digit = sum % 10;

            // Carry for next position
            carry = sum / 10;

            // Create new node
            current->next = new ListNode(digit);

            current = current->next;
        }

        return dummy->next;
    }
};