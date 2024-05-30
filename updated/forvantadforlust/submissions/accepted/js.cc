#include <cstdio>

int main(){
    int n, k;
    double d;
    scanf("%d%d%lf", &n, &k, &d);
    if(n*d < k){
        printf("Spela\n");
    } else {
        printf("Spela inte!\n");
    }
}
