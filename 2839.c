#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int d5 = n / 5, d3;
    int res;
    int count = n;

    for(int i = d5; i >= 0; i--){
        res = n - i * 5;
        if(res % 3 != 0)
            continue;
        d3 = res / 3;
        if(i + d3 < count)
            count = i + d3;
    }
    printf("%d", count == n ? -1 : count);
}