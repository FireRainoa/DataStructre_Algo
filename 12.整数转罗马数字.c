/*
 * @lc app=leetcode.cn id=12 lang=c
 *
 * [12] 整数转罗马数字
 */

// @lc code=start
char* intToRoman(int num) {
    int arr[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char* str[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    char* s = (char *)malloc(20 * sizeof(char));
    memset(s, 0, 20);
    for (int i = 0; i < 13; i++) {  
        while (num >= arr[i]) {
            strcat(s, str[i]);
            num -= arr[i];  
            if(num == 0) break;
        }
    }
    return s;
}
// @lc code=end

