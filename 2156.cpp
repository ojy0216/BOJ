#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX 10000

int wine[MAX + 1] = {0, };
int dp[MAX + 1] = {0, };

void f(int n){
    int x = dp[n - 2] + wine[n];
    int y = dp[n - 3] + wine[n - 1] + wine[n];
    int z = dp[n - 1];
    dp[n] = max(x, max(y, z));
}

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d", &wine[i + 1]);

    if(n >= 1)
        dp[1] = wine[1];
    if(n >= 2)
        dp[2] = wine[1] + wine[2];
    if(n >= 3)
        dp[3] = max(wine[1] + wine[2], max(wine[1] + wine[3], wine[2] + wine[3]));
    if(n >= 4){
        for(int i = 4; i <= n; i++)
            f(i);
    }

    printf("%d", dp[n]);
}