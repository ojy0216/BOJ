#include <stdio.h>

int main(){
    int t;
    scanf("%d", &t);

    for(int i = 0; i < t; i++){
        int h, w, n;
        int y, x;
        scanf("%d %d %d", &h, &w, &n);
        x = (n % h) == 0 ? (n / h) : (n / h) + 1;
        y = (n % h) == 0 ? h : n % h;

        printf("%d%02d\n", y, x);
    }
}