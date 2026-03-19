/*
 * @lc app=leetcode.cn id=34 lang=c
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int binary(int *a, int target, int len) {
    // l = -1 视为-∞ , r视为+∞;
    int l = -1;
    int r = len;
    // 此处循环条件是陷入死循环的重要节点
    // while (l < r);例如l=-1;r=6,在第四次循环时,l=2,r=3;会陷入死循环
    while (l + 1 < r) {
        int mid = l + (r - l) / 2;
        // 在中点小于目标时,则截取左部分
        if (a[mid] < target) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return r;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int *arr = malloc(sizeof(int) * 2);
    arr[0] = -1;
    arr[1] = -1;
    *returnSize = 2;

    // 如果是空数组,则直接返回
    if(numsSize == 0) {
        return arr;
    }

    // 1.找到左端点
    int left = binary(nums, target, numsSize);

    // 得到左端点时,要判断左端点合法性
    if(left >= numsSize || nums[left] != target) return arr;

    // 2.找到右端点,找到第一个大于目标的下标,-1即为最后一个目标下标
    int right = binary(nums, target + 1, numsSize) - 1;
    arr[0] = left;
    arr[1] = right;
    return arr;
}
// @lc code=end

