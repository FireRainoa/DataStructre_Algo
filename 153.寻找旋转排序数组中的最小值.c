/*
 * @lc app=leetcode.cn id=153 lang=c
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
int findMin(int* nums, int numsSize) {
    // l=-1：非法下标，作为左边界，确保查找范围从0开始；r=numsSize-1：数组最后一个合法下标
    int l = -1, r = numsSize - 1;
    while (l + 1 < r){
        int mid = l + (r - l) / 2;
        // 核心逻辑：以最后一个元素nums[numsSize-1]为锚点，区分mid所在的段
        // 旋转排序数组特性：左段（旋转前的后半段）所有元素 > 右段（旋转前的前半段）所有元素
        // nums[mid] < nums[numsSize-1]：mid在右段，最小值在mid左侧（含mid），收缩右边界
        if (nums[mid] < nums[numsSize - 1]){
            r = mid;
        } else {
            l = mid;
        }
    }
    // 循环终止时l+1=r：
    // l是最后一个属于左段的下标（或-1），r是第一个属于右段的下标（右段第一个元素即数组最小值）
    return nums[r];
}
// @lc code=end

