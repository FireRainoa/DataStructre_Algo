/*
 * @lc app=leetcode.cn id=5 lang=c
 *
 * [5] 最长回文子串
 */

// @lc code=start
void expandString(char* s, int l, int r, int* start, int * len) {
    while (l >= 0 && r < strlen(s) && s[l] == s[r]) {
        l --;
        r ++;
    }
    // 循环退出时 l/r 已超出有效边界
    int curlen = r - l - 1;
    if (curlen > *len) {
        // 在上方代码中,判断相等的逻辑代码在循环条件中,造成一个问题
        // 在不相等的时候, l--已经执行,所以此处应该让start = l + 1;
         *start = l + 1;
         *len = curlen;
    }
}

char* longestPalindrome(char* s) {
    int n = strlen(s);
    if (n < 2) {
        return s;
    }

    int start = 0;
    int len = 1;
    for (int i = 0; i < strlen(s); i ++ ){
        expandString(s, i, i, &start, &len);    // 处理奇数长度的字符串, 中间字符一个
        expandString(s, i, i + 1, &start, &len);// 偶数长度字符串,中间字符是两个;
    }
    s[start + len] = '\0';
    return s + start;
}
// @lc code=end

