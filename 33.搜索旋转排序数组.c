/*
 * @lc app=leetcode.cn id=33 lang=c
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
int search(int* nums, int numsSize, int target) {
    int l = -1, r = numsSize - 1, mid;
    // 取最后一个元素作为锚点：旋转数组分为左段（>last）和右段（≤last）
    int last = nums[numsSize - 1];
    // 常规开区间写法
    while (l + 1 < r) {
        mid = l + (r - l) / 2;
        int n = nums[mid];
        // 若是目标比最后一个数字大,且中点小于最后一个数字,说明中点在右段，目标在左段→收缩右边界
        if(target > last && n <= last) r = mid;
        // 中点大于最后一个数字,且目标小于最后一个数字,说明中点在左段，目标在右段→收缩左边界
        else if(n > last && target <= last) l = mid;
        // 上述都不符合, mid和target同段（左段/右段）→ 按升序数组常规二分查找
        else if(n >= target) r = mid;
        else l = mid;
    }
    // 若是nums[r]不等于target,即没找到,返回-1;
    return  nums[r] == target ? r : -1;
}
// @lc code=end

    