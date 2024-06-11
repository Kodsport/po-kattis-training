#include <stdio.h>

int main() {
  int i,j,k,m,n,s[100000];
  scanf("%d", &n);
  s[0]=0;
  for(i=1;s[i-1]<=n;i++) s[i]=s[i-1]+i;
  for(j=1;j<i;j++) {
    m=0;
    for(k=j;m<n;k++) {
      m+=s[k];
    }
    if(m==n) {
      printf("%d %d\n", j, k-1);
      return 0;
    }
  }
  printf("NEJ\n");
  return 0;
}
    
