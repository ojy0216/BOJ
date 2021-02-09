#include <stdio.h>

int main(){
    int a, b, v;
    scanf("%d %d %d", &a, &b, &v);

    int n = (v - a) / (a - b);
    int res = (v - a) % (a - b);

    if(res == 0)
        n += 1;
    else
        n += 2;
    
    printf("%d", n); 
}