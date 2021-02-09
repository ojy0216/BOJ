#include <stdio.h>

#define TRUE 1;
#define FALSE 0;

int f(int n){
    int count = 0;
    int arr[4] = {0, };
    for(int i = 0; i < 4; i++){
        if(n > 0)
            count++;
        arr[i] = n % 10;
        n /= 10;
    }
    if(count <= 2)
        return TRUE;

    int interval = arr[0] - arr[1];

    for(int i = 1; i <= count - 2; i++){
        if(arr[i] - arr[i + 1] != interval)
            return FALSE;
    }

    return TRUE;
}

int main(){
    int n;
    scanf("%d", &n);
    int count = 0;

    for(int i = 1; i <= n; i++)
        count += f(i);

    printf("%d", count);
}