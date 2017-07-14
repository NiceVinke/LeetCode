// Remove all elements from a linked list of integers that have value val.
//
// Example
// Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6,  val = 6
// Return: 1 --> 2 --> 3 --> 4 --> 5
//
//
// Credits:Special thanks to @mithmatt for adding this problem and creating all test cases.


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
    ListNode* removeElements(ListNode* head, int val)
    {
        ListNode **list = &head;
        while (*list) {
            if ((*list)->val == val)
                *list = (*list)->next;
            else
                list = &(*list)->next;
        }
        return head;
    }
};
