#include <cstdio>
using namespace std;

constexpr int mod = 1000000007;

long long factorial(int n){
    long long x = 1;
    for(int i = n; i > 1; i--)
        x = (x * i) % mod;
    return x;
}

long long pow(long long a, int b, int c){
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
    int n, k;
    scanf("%d %d", &n, &k);

    long long result = factorial(n);
    result *= pow(factorial(k), mod - 2, mod);
    result %= mod;
    result *= pow(factorial(n - k), mod - 2, mod);
    result %= mod;

    printf("%lld", result);
}