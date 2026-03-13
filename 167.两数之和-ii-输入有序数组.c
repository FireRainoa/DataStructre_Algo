/*
 * @lc app=leetcode.cn id=167 lang=c
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int l = 0, r = numbersSize - 1;
    while (l < r) {
        int s = numbers[l] + numbers[r];
        if (s == target) {
            *returnSize = 2;
            int* arr = malloc(sizeof(int) * 2);
            arr[0] = l + 1, arr[1] = r + 1;
            return arr;
        }
        s > target ? r -- : l ++;
    }
    return NULL;
}
// @lc code=end

