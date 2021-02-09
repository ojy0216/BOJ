#include <stdio.h>

int main(){
    int a, b, c, x;
    int arr[10] = {0, };

    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    x = a * b * c;

    while(x > 0){
        arr[x % 10]++;
        x /= 10;
    }

    for(int i = 0; i < 10; i++)
        printf("%d\n", arr[i]);
}