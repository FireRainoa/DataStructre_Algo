/*
 * @lc app=leetcode.cn id=1456 lang=c
 *
 * [1456] 定长子串中元音的最大数目
 */

// @lc code=start
#define MAX(a,b) ((a) > (b) ? (a) : (b))
int maxVowels(char* s, int k) {
    // vowel 表示元音字母个数
    int vowel = 0, res = 0;
    for (int i = 0; s[i]; i ++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            vowel ++; // 当是元音字母时,原因个数++
        }

        // 手动计算左端点,比如 i=2、k=3 时，left=0，窗口是 [0,2]
        int l = i - k + 1;
        // 如果l小于0,就是无效下标,跳过
        if (l < 0) continue;
        res = MAX(res, vowel);
        // 优化点
        if(res == k) break;

        // 应为每轮循环l都会跟着右端点i走,那么在走之前如果是元音字母就要减掉
        if (s[l] == 'a' || s[l] == 'e' || s[l] == 'i' || s[l] == 'o' || s[l] == 'u') {
            vowel --;
        }
    }
    return res;
}
// @lc code=end

