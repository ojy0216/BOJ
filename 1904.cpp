#include <iostream>
using namespace std;

enum {MAX = 1000001, MOD = 15746};

int fib[MAX];

void f(int n){
    for(int i = 3; i <= n; i++)
        fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
}


int main(){
    int n;

    scanf("%d", &n);
    fib[0] = 0;
    fib[1] = 1;
    fib[2] = 2;

    f(n);

    printf("%d", fib[n]);
}