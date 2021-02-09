#include <stdio.h>
#include <stdlib.h>

int f(int a, int b){
    if(a == 0)
        return b;
    
    int x = 0;
    for(int i = 1; i <= b; i++)
        x += f(a - 1, i);

    return x;
}

int main(){
    int t;
    scanf("%d", &t);

    for(int i = 0; i < t; i++){
        int a, b;
        scanf("%d", &a);
        scanf("%d", &b);

        printf("%d\n", f(a, b));

    }
}