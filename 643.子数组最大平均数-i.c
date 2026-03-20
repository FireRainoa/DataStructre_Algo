/*
 * @lc app=leetcode.cn id=643 lang=c
 *
 * [643] 子数组最大平均数 I
 */

// @lc code=start
#define MAX(a, b) ((a) > (b) ? (a) : (b))
double findMaxAverage(int* nums, int numsSize, int k) {
    int maxn = INT_MIN;
    int res = 0;
    int sum = 0;
    for(int r = 0; r < numsSize; r ++) {
        sum += nums[r];
        if (r < k - 1) continue;
        maxn = MAX(maxn, sum);
        sum -= nums[r - k + 1];
    }
    return (double) maxn / k;
}
// @lc code=end

