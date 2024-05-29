#include <stdio.h>

int main() {
  int i,n,s;
  scanf("%d", &n);
  for(i=1,s=0;s+i<=n;i++) s+=i;
  printf("%d\n", i-1);
  return 0;
}
    
