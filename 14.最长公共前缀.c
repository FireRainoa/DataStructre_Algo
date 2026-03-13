/*
 * @lc app=leetcode.cn id=14 lang=c
 *
 * [14] 最长公共前缀
 */

// @lc code=start
char* longestCommonPrefix(char** strs, int strsSize) {
    char* s0 = strs[0];
    for (int j = 0; s0[j]; j++) {
        for (int i = 0; i < strsSize; i++) {
            if (s0[j] != strs[i][j]) {
                int l = j + 1;
                char* s = malloc(j + 1);
                // strncpy 核心是 “限定长度拷贝字符串”，相比 strcpy 可避免缓冲区溢出，但不会自动补 \0；
                // char *strncpy(char *dest, const char *src, size_t n);
                strncpy(s, s0, j);
                s[j] = '\0';
                return s;
            }
        }
    }
    return s0;
}
// @lc code=end

