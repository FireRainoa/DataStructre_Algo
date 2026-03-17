/*
 * @lc app=leetcode.cn id=713 lang=c
 *
 * [713] 乘积小于 K 的子数组
 */

// @lc code=start
int numSubarrayProductLessThanK(int* nums, int numsSize, int k) {
    // 注意边界条件,当k <= 1时,则不可能完全满足小于k的子数组
    if (k <= 1) return 0;
    int res = 0;
    int l = 0;
    int multi = 1;
    for (int r = 0; r < numsSize; r++) {
        multi *= nums[r];
        while (multi >= k) {
            multi /= nums[l];
            l ++;         
        }
        res += r - l + 1;
    }
    return res;
}
// @lc code=end

