#include <cstdio>
#include <vector>

using namespace std;

vector<int> ans;

void rec(int a, int b, int* num){
    if (b < *num) rec(b, a+b, num);
    while(b <= *num){
        *num = *num - b;
        ans.push_back(b);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    rec(0, 1, &n);
    printf("%u\n", ans.size());
    for(int i = 0; i<ans.size(); i++) printf("%d\n", ans[i]);
}
