// Given a linked list, determine if it has a cycle in it.
//
//
//
// Follow up:
// Can you solve it without using extra space?


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
    bool hasCycle(ListNode *head)
    {
        if (!head || !head->next || !head->next->next)
            return false;
        ListNode *slow = head;
        ListNode *fast = head->next->next;
        while (slow != fast) {
            slow = slow->next;
            if (fast->next && fast->next->next)
                fast = fast->next->next;
            else
                return false;
        }
        return true;
    }
};
