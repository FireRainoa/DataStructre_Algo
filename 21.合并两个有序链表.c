/*
 * @lc app=leetcode.cn id=21 lang=c
 *
 * [21] 合并两个有序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy -> next = NULL;
    dummy -> val = 0;
    struct ListNode* cur = dummy;
    if(list1 == NULL) return list2;
    if(list2 == NULL) return list1;
    struct ListNode* p1 = list1;
    struct ListNode* p2 = list2;
    while (p1 != NULL && p2 != NULL){
        if(p1->val <= p2->val) {
            cur->next = p1;
            p1 = p1->next;
            cur = cur->next;
        }else {
            cur->next = p2;
            p2 = p2->next;
            cur = cur->next;
        }
    }
    while (p1 != NULL){
        cur->next = p1;
        p1 = p1->next;
        cur = cur->next;
    }
    while (p2 != NULL){
        cur->next = p2;
        p2 = p2->next;
        cur = cur->next;
    }
    
    return dummy->next;
}
// @lc code=end

