#include <iostream>

using namespace std;

int main(){
    printf("1000 1000\n");
    for(int i = 0; i < 1000; ++i){
        for(int j = 0; j < 1000; ++j){
            if(j == 500 && 0 < i && i < 999) printf(".");
            else if((j == 499 || j == 501) && 0 < i && i < 999) printf("#");
            else if(i == 1 && j > 0 && j < 999) printf("#");
            else if(j == 1 && i > 0 && i < 999) printf("#");
            else if(i == 998 && j > 0 && j < 999) printf("#");
            else if(j == 998 && i > 0 && i < 999) printf("#");
            else if ( (i >= 2 && i < 998) && (j >= 2 && j < 998)) printf("X");
            else printf(".");
        }
        printf("\n");
    }
}
