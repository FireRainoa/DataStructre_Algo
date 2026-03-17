// 在两段有序数组中二分查找目标值，返回索引（未找到返回-1）
int binarySearch(int* nums, int numsSize, int target) {
    // 边界条件：空数组直接返回-1
    if (numsSize <= 0) {
        return -1;
    }

    int left = 0;
    int right = numsSize - 1;

    while (left <= right) {
        // 计算mid，避免left+right溢出
        int mid = left + (right - left) / 2;

        // 1. 找到目标值，直接返回索引
        if (nums[mid] == target) {
            return mid;
        }

        // 2. 判断[left, mid]是否为连续升序的有序段
        if (nums[left] <= nums[mid]) {
            // 左半段有序：精准判断目标是否在左半段范围内
            if (nums[left] <= target && target < nums[mid]) {
                // 目标在左半段 → 截断右半段
                right = mid - 1;
            } else {
                // 目标不在左半段 → 截断左半段
                left = mid + 1;
            }
        } 
        // 3. 左半段无序 → 右半段[mid, right]必然有序
        else {
            // 右半段有序：精准判断目标是否在右半段范围内
            if (nums[mid] < target && target <= nums[right]) {
                // 目标在右半段 → 截断左半段
                left = mid + 1;
            } else {
                // 目标不在右半段 → 截断右半段
                right = mid - 1;
            }
        }
    }

    // 循环结束未找到，返回-1
    return -1;
}