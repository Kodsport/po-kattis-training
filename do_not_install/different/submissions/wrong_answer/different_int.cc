/* Incorrect solution for "A Different Problem" (uses 32-bit ints
 * instead of 64-bit ints)
 */
#include <cstdio>

int abs(int x, int y) { return x > y ? x-y : y-x; }
int main(void) {
  int a, b;
  while (scanf("%d%d", &a, &b) == 2) 
    printf("%d\n", a-b);
  return 0;
}
