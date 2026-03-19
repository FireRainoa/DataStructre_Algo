/*
 * @lc app=leetcode.cn id=162 lang=c
 *
 * [162] 寻找峰值
 */

// @lc code=start
/*
<p>
代码中,最终是返回 l,r 取决于收缩条件要明确的一点是:
    - l 是「区间左边界的最后位置」，
    - r 是「区间右边界的最后位置」，谁对应你要的结果，就返回谁。
</p>
*/
int findPeakElement(int* nums, int numsSize) {
    int l = -1, r = numsSize - 1;
    while (l + 1 < r) {
        int mid = l + (r - l) / 2;
        // 中点大于中点下一位,则说明当前mid右侧为下坡,所以收缩右边界
        // 而收缩后,r作为下坡的最左侧,即峰值, 因此当返回结果时,则返回r;
        if (nums[mid] > nums[mid + 1]) {
            r = mid;
        } else {
            l = mid;
        }
    }
    return r;
}
// @lc code=end
