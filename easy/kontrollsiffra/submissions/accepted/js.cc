#include <cstdio>

int main(){
    int ans = 0, k;
    for(int i = 0; i<9; i++){
        scanf("%d", &k);
        ans += (i%2 ? 7 : 3)*k;
    }
    printf("%d\n", ans%10);
}
