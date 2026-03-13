/*
 * @lc app=leetcode.cn id=9 lang=c
 *
 * [9] 回文数
 */

// @lc code=start
bool isPalindrome(int x) {
    if(x < 0) return false;
    long long res = 0, num = x;
    while (num != 0) {
        int a = num % 10;
        res = res* 10 + a;
        num /= 10;
    }
    return res == x;
}
// @lc code=end

