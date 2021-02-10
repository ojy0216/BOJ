#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    vector<int> v(n + 1);
    vector<int> dp(n + 1, -1000);
    for(int i = 1; i <= n; i++)
        scanf("%d", &v[i]);

    for(int i = 1; i <= n; i++){
        dp[i] = max(dp[i - 1] + v[i], v[i]);
    }

    printf("%d", *max_element(dp.begin() + 1, dp.end()));
}