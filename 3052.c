#include <stdio.h>

int main(){
    int in, count = 0;
    int mod[42] = {0, };
    
    for(int i = 0; i < 10; i++){
        scanf("%d", &in);
        mod[in % 42]++;
    }

    for(int i = 0; i < 42; i++){
        if(mod[i] != 0)
            count++;
    }

    printf("%d", count);
}