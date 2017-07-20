// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
//
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
//
// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *oldL1 = l1, *oldL2 = l2;
        int sum = 0, carry = 0, tmp = 0;
        for (;;) {
            sum = l1->val + l2->val + carry;
            if (sum > 9) {
                sum -= 10;
                carry = 1;
            } else
                carry = 0;
            l1->val = l2->val = sum;

            tmp = (l1->next ? 0 : 1) + (l2->next ? 0 : 1);
            if (tmp == 0) {
                l1 = l1->next;
                l2 = l2->next;
                continue;
            } else if (tmp == 1) {
                auto l = (l1->next ? l1->next : l2->next);
                while (carry) {
                    if ((l->val += carry) > 9) {
                        l->val -= 10;
                        carry = 1;
                        if (!l->next) {
                            l->next = new ListNode(1);
                            return l1->next ? oldL1 : oldL2;
                        }
                        l = l->next;
                    } else
                        return l1->next ? oldL1 : oldL2;
                }
                return l1->next ? oldL1 : oldL2;
            } else {
                if (carry)
                    l1->next = new ListNode(1);
                return oldL1;
            }
        }
    }
};
