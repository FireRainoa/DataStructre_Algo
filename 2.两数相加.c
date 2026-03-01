 /*
 * @lc app=leetcode.cn id=2 lang=c
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* res = (struct ListNode*)malloc(sizeof(struct ListNode));
    res -> next = NULL;
    res -> val = 0;
    struct ListNode* cur = res;
    int carry = 0;
    while(l1 != NULL || l2 != NULL || carry != 0) {
        int va1 = (l1 != NULL) ? l1->val : 0;
        int va2 = (l2 != NULL) ? l2->val : 0;
        int sum = va1 + va2 + carry;
        carry = sum / 10;

        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode -> val = sum % 10;
        newNode -> next = NULL;
        cur->next = newNode;
        cur = cur->next;

        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
    }
    return res->next;
}
// @lc code=end



