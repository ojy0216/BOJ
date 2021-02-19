#include <cstdio>
#include <algorithm>
using namespace std;

int GCD(int x, int y){
    int r;
    while(y){
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}

int LCM(int x, int y){
    int i = 1;
    while(true){
        if(x * i % y == 0)
            break;
        i++;
    }
    return x * i;
}

int main(){
    int x, y;
    scanf("%d %d", &x, &y);

    printf("%d\n%d", GCD(x, y), LCM(x, y));
}