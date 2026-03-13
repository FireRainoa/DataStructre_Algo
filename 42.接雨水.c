/*
 * @lc app=leetcode.cn id=42 lang=c
 *
 * [42] 接雨水
 */

// @lc code=start
#define MAX(a, b) ((a) > (b) ? (a) : (b))
int trap(int* height, int heightSize) {
    // 初始化左右边界, 前缀最大值和后缀最大值;
    int l = 0, r = heightSize - 1, pre_max = 0, sub_max = 0;
    int res = 0;
    while (l < r) {
        // 更新前后缀最大值
        pre_max = MAX(height[l], pre_max);
        sub_max = MAX(height[r], sub_max);
        // 如果前缀小于后缀,那说明,当前这个桶的高度,最高就是pre_max;
        if (pre_max < sub_max) {
            res += pre_max - height[l];
            l ++;
        }else {
            res += sub_max - height[r];
            r --;
        }
    }
    return res;
}
// @lc code=end

