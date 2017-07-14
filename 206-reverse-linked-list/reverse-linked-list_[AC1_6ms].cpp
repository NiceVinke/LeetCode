// Reverse a singly linked list.
//
// click to show more hints.
//
// Hint:
// A linked list can be reversed either iteratively or recursively. Could you implement both?


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
    ListNode* reverseList(ListNode* head)
    {
        if (!head || !head->next)
            return head;
        
        ListNode *nextHead = head->next;

        ListNode *tmp = nextHead->next;
        nextHead->next = head;
        head->next = nullptr;
        head = nextHead;
        nextHead = tmp;

        while (nextHead) {
            tmp = nextHead->next;
            nextHead->next = head;
            head = nextHead;
            nextHead = tmp;
        }

        return head;
    }
};
