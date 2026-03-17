/*
【算法25】圆周率π是数学中重要的常数，核心公式如下:π/4≈(1-1/3+1/5-1/7...)
要求累加到最后一项绝对值小于10-6为止。
*/
#include <stdio.h>

int main(int argc, char const* argv[]) {
  double res = 1.0;
  int n = 3, sign = -1;
  double cur = 1.0 / n;
  while (cur >= 1e-6) {
    res += sign * cur;
    n += 2;
    sign = -sign;
    cur = 1.0 / n;
  }
  printf("%lf", res * 4);
  return 0;
}