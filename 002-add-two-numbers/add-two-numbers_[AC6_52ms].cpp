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
        bool carry = false;
        for (;;) {
            l1->val += ((l2 ? l2->val : 0) + (carry ? 1 : 0));
            if (l1->val > 9) l1->val -= 10, carry = true;
            else carry = false;
            if (l2) l2 = l2->next;
            if (!l1->next && !l2) break;
            if (!l1->next) l1->next = l2, l2 = nullptr;
            l1 = l1->next;
        }
        if (carry) {
            bak->val = 1;
            bak->next = nullptr;
            l1->next = bak;
        }
        return ans;
    }
};
