/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    // the (fast) one-pass method
    struct ListNode i = { 0, head };
    struct ListNode* a, * b;
    a = b = &i;
    while (n--) b = b->next;
    while (b = b->next) a = a->next;
    i.val = (head == a->next);
    a->next = a->next->next;
    return i.val * (intptr_t)a->next + !i.val * (intptr_t)head;
}