/*
 * @lc app=leetcode.cn id=11 lang=c
 *
 * [11] 盛最多水的容器
 */

#define MAX(a, b) ((a) > (b) ? (a) : (b))
// @lc code=start
int maxArea(int* height, int heightSize) {
    int l = 0,r = heightSize - 1;
    int max = 0;
    while (l < r) {
        if (height[l] < height[r]) {
            max = MAX(max, (r - l) * height[l]);
            l ++;
        }else {
            max = MAX(max, (r - l) * height[r]);
            r --;
        }
        
    }
    return max;
}
// @lc code=end

