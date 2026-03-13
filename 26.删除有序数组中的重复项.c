/*
 * @lc app=leetcode.cn id=26 lang=c
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
int removeDuplicates(int* nums, int numsSize) {
    // 1.初始化k = 1;
    //   - 有序数组的第一个元素（nums[0]）一定是唯一的，无需处理；
    //   - k指向「下一个要放置不重复元素的位置」（初始为nums[1]）。
    int k = 1;
    // 2. i从1开始遍历数组（跳过已确定的nums[0]）：
    for(int i = 1; i < numsSize; i++) {
        // 如果当前数字和前一个不同,则放置在k位置!!
        // 3. 核心判断：当前元素与前一个元素不同 → 说明是新的不重复元素
        // 4. 把不重复元素放到k的位置，然后k后移（指向下一个空位）
        if (nums[i] != nums[i - 1]) nums[k ++] = nums[i];
        // 5. 若当前元素与前一个重复 → 跳过，i继续后移
    }

    return k;
}
// @lc code=end

