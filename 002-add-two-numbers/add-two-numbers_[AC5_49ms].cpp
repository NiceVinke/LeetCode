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
        ListNode *ans = l1, *bak = l2;
        int sum = 0, tmp = 0;
        bool carry = false;
        for (;;) {
            sum = l1->val + l2->val + carry;
            if (sum > 9) {
                sum -= 10;
                carry = true;
            } else
                carry = false;

            l1->val = sum;

            tmp = (l1->next ? 0 : 1) + (l2->next ? 0 : 1);

            if (tmp == 0) {
                l1 = l1->next;
                l2 = l2->next;
                continue;
            }
            if (tmp == 1) {
                if (!l1->next)
                    l1->next = l2->next;

                while (l1->next) {
                    l1 = l1->next;
                    if (carry && ++l1->val > 9)
                        l1->val -= 10;
                    else
                        return ans;
                }
            }
            break;
        }
        if (carry) {
            bak->val = 1;
            bak->next = nullptr;
            l1->next = bak;
        }
        return ans;
    }
};
