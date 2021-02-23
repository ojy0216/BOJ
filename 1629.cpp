#include <cstdio>
using namespace std;

long long pow(int a, int b, int c){
    long long x = a;
    long long y = (b % 2)? a : 1;
    int n = b / 2;

    if(n == 0)
        y %= c;

    while(n > 0){
        x = (x * x) % c;
        if(n % 2)
            y = (y == 1) ? x : (x * y) % c;
        n /= 2;
    }
    return y;
}

int main(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    printf("%lld", pow(a, b, c));
}