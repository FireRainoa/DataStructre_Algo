/*
 * @lc app=leetcode.cn id=13 lang=c
 *
 * [13] 罗马数字转整数
 */

// @lc code=start

int getnum(char c)
{
    switch (c)
    {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    default:
        return 0;
    }
}

int romanToInt(char *s)
{
    int sum = 0;
    int l = strlen(s);
    for (int i = 0; i < l; i++)
    {
        int cur = getnum(s[i]);
        if (i < l - 1 && cur < getnum(s[i + 1]))
        {
            sum -= getnum(s[i]);
        }
        else
        {
            sum += getnum(s[i]);
        }
    }
    return sum;
}
// @lc code=end
