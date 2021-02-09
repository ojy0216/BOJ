#include <stdio.h>

int main(){
    int x;
    int n = 1;
    scanf("%d", &x);
    int y = x, tmp, a, b;

    while(1){
        a = y / 10;
        b = y % 10;
        tmp = a + b;
        y = 10 * b + (tmp % 10);
        if(y == x)
            break;
        n++;
    }
    printf("%d", n);
}