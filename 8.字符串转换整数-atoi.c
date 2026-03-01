/*
 * @lc app=leetcode.cn id=8 lang=c
 *
 * [8] 字符串转换整数 (atoi)
 */

#include <ctype.h>
#include <stdint.h>
// @lc code=start
int myAtoi(char *s)
{
    while (*s != '\0')
    {
        if (*s != '\0' && isspace(*s))
        {
            s++;
            continue;
        }
        else {
            break;
        }
    }

    long long res = 0;
    int sign = 1;
    if (*s == '+' || *s == '-')
    {
        sign = (*s == '+') ? 1 : -1;
        // 判断完符号位后,跳过当前位
        s++;
    }

    while (*s != '\0' && isdigit((unsigned char)*s))
    {
        int digit = *s - '0';
        res = res * 10 + digit;
        if (sign == 1 && res > INT32_MAX)
            return INT32_MAX;
        if (sign == -1 && -res < INT32_MIN)
            return INT32_MIN;
        s++;
    }
    return (int)(sign * res);
}
// @lc code=end
