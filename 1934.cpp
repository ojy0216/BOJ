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

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        int x, y;
        scanf("%d %d", &x, &y);

        int gcd = GCD(x, y);
        int lcm = x * y / gcd;
        printf("%d\n", lcm);
    }
}