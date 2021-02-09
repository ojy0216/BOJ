#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX 300

int stair[MAX + 1] = {0, };
int dp[MAX + 1] = {0, };

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d", &stair[i]);

    dp[0] = stair[0];
    dp[1] = stair[0] + stair[1];
    dp[2] = max(stair[0] + stair[2], stair[1] + stair[2]);

    for(int i = 3; i < n; i++)
        dp[i] = max(dp[i - 2] + stair[i], dp[i - 3] + stair[i - 1] + stair[i]);

    printf("%d", dp[n - 1]);
}