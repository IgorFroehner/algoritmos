#include <bits/stdc++.h>

int fast_exp(int b, int n)
{
  int res = 1;
  int x = b;

  while (n > 0) {
    if (n & 0x01) {
      n--;
      res *= x;
    } else {
      n >>= 1;
      x *= x;
    }
  }

  return res;
}

int main(void)
{
  int b, n;

  while (scanf("%d %d", &b, &n) == 2) {
    printf("%d^%d = %d\n", b, n, fast_exp(b, n));
  }
  return 0;

}