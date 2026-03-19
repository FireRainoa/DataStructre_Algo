/*
 * @lc app=leetcode.cn id=852 lang=c
 *
 * [852] 山脉数组的峰顶索引
 */

// @lc code=start
int peakIndexInMountainArray(int* arr, int arrSize) {
    // r = size - 2; 原因是当下标为最后一位时,不会存在拐点
    int l = 0, r = arrSize - 2;
    while (l + 1 < r) {
        // 防止溢出
        int mid = l + (r - l) / 2;
        // 当中点大于右边,则说明拐点在中点左侧,收紧右边界
        if (arr[mid] > arr[mid + 1]){
            r = mid;
        } else {
            // 中点小于右侧,则说明拐点在右侧,收紧左边界
            l = mid;
        }
    }
    return r;
}
// @lc code=end

