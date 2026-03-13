/*
 * @lc app=leetcode.cn id=209 lang=c
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
int minSubArrayLen(int target, int* nums, int numsSize) {
    if(numsSize <= 1) return nums[0] >= target ? 1 : 0;
    int l = 0, r = 0;
    // 此处无需初始超大数字,只需等于numsSize + 1即可
    // int res = 1e10;
    int res = numsSize + 1;
    int sum = 0;
    while (r < numsSize) {
        sum += nums[r];
        while (sum >= target){
            res = res < (r - l + 1) ? res : (r - l + 1);
            sum -= nums[l];
            l ++;
        }
        r ++;
    }
    return res <= numsSize ? res : 0;
}
// @lc code=end

