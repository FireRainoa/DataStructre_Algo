/*
 * @lc app=leetcode.cn id=1343 lang=c
 *
 * [1343] 大小为 K 且平均值大于等于阈值的子数组数目
 */

// @lc code=start
#define MAX(a, b) ((a) > (b) ? (a) : (b))
int numOfSubarrays(int* arr, int arrSize, int k, int threshold) {
    int s = 0, res = 0;
    for (int i = 0; i < arrSize; i++) {
        s += arr[i];
        if (i < k - 1) continue;
        if (s >= k * threshold) res ++;
        s -= arr[i - k + 1];
    }
    return res;
}
// @lc code=end

