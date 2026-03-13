/*
 * @lc app=leetcode.cn id=20 lang=c
 *
 * [20] 有效的括号
 */

// @lc code=start
bool isValid(char *s)
{
    for (int k = 0; k < strlen(s) - 1; k++)
    {
        switch (s[k])
        {
        case '(':
            if (s[k + 1] == ')')
                return true;
            return false;
        case '[':
            if (s[k + 1] == ']')
                return true;
            return false;
        case '{':
            if (s[k + 1] == '}')
                return true;
            return false;
        }
    }
    return false;
}
// @lc code=end
