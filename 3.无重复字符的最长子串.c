/*
 * @lc app=leetcode.cn id=3 lang=c
 *
 * [3] 无重复字符的最长子串
 */

#define MAX(a,b) ((a) > (b) ? (a) : (b))
// @lc code=start
int lengthOfLongestSubstring(char* s) {
    int max = 0, left = 0;
    int arr[128] = {0};
    for (int right = 0; s[right]; right ++) {
        char c = s[right];
        arr[c] ++;
        while (arr[c] > 1) {
            arr[s[left]] --;
            left ++;
        }
        max = MAX(max, right - left + 1);
    }
    return max;
}
// @lc code=end

