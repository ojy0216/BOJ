#include <cstdio>
using namespace std;

int main(){
    while(true){
        int x, y;
        scanf("%d %d", &x, &y);

        if(x == 0 && y == 0)
            break;

        if(y % x == 0)
            printf("factor\n");
        else if(x % y == 0)
            printf("multiple\n");
        else
            printf("neither\n");
    }
}