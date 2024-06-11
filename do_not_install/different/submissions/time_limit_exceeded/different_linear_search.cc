/* TLE solution for "A Different Problem" (does linear search for the
 * answer...)
 */
#include <cstdio>

long long abs(long long x) { 
  return x > 0 ? x : -x; 
}

int main(void) {
  long long a, b;
  while (scanf("%lld%lld", &a, &b) == 2)  {
    for (long long x = 0; ; ++x) 
      if (a-b == x || b-a == x) {
	printf("%lld\n", x);
	break;
      }
  }
  return 0;
}
