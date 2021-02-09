#include <stdio.h>

int main(){
    int arr[9];
    int n;

    for(int i = 0; i < 9; i++)
        scanf("%d", &arr[i]);

    int max = arr[0], idx = 0;

    for(int i = 1; i < 9; i++){
        if(arr[i] > max){
            idx = i;
            max = arr[i];
        }
    }

    printf("%d\n%d", max, idx + 1);
}