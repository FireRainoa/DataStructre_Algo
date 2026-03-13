/*
 * @lc app=leetcode.cn id=19 lang=c
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* dummy = (struct ListNode*) malloc(sizeof(struct ListNode));
    dummy -> val = 0;
    dummy->next = head;
    struct ListNode* fast = dummy;
    struct ListNode* slow = dummy;
    for(int i = 0; i<= n; i++){
        fast = fast->next;
    }

    while(fast != NULL){
        fast=fast->next;
        slow=slow->next;
    }

    slow -> next = slow->next->next;
    return dummy->next;
}
// @lc code=end

