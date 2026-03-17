/*
谁频次最高
 - 题目： 统计一个整型序列中出现次数最多的整数及其出现次数
 - 输入： 输入在一行中给出序列中整数个数 N(0<N<1000)，以及 N 个整数。数字间以空格分隔
 - 输出： 在一行中输出出现次数最多的整数及其出现次数，数字间以空格分隔。题目保证这样的数字是唯一的

 - 输入样例：
11
10 3 2 -1 5 3 4 3 0 3 2

 - 输出样例：
3 4
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(){
    int n ;
    scanf("%d", &n);

    long long x = LLONG_MIN,y = LLONG_MAX;
    int a = INT_MAX, b = INT_MIN;
    printf("%lld, %lld\n", x, y);
    printf("%d, %d", a, b);

    int arr[n];
    int a;
    int max = INT_MIN, min = INT_MAX;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        arr[i] = a;
        max = max > a ? max : a;
        min = min < a ? min : a;
    }
    // 错误：若max=0（输入全0），数组长度为0，非法；且未考虑数字为负数的情况
    // int cnt[max];
    int offset = -min;
    int len = max - min + 1;
    int cnt[len];
    for (int i = 0; i < len; i++) cnt[i] = 0;

    for (int i = 0; i < n; i++) {
        // 错误：统计逻辑错误！应该是 cnt[arr[i]]++，而非 cnt[i]++
        // cnt[i] ++;
        cnt[arr[i]] ++;
    }

    int max_index = 0;
    for (int i = 1; i < len; i++) {
        if (cnt[i] > cnt[max_index]) max_index = i;                
    }

    // TODO 当是负数时,进行下标转换

    printf("最多次数字为： %d, 次数：%d", max_index, cnt[max_index]);
    
}