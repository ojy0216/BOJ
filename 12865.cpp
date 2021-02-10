#include <cstdio>
#include <algorithm>
using namespace std;

constexpr int maxN = 100, maxK = 100000;

int arr[maxN + 1][2] = {0, }; // weight, value;
int v[maxN + 1][maxK + 1] = {0, };

int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    for(int i = 1; i <= n; i++)
        scanf("%d %d", &arr[i][0], &arr[i][1]);

    for(int i = 1; i <= n; i++){
        for(int w = 1; w <= k; w++){
            if(arr[i][0] > w)
                v[i][w] = v[i - 1][w];
            else
                v[i][w] = max(v[i - 1][w], v[i - 1][w - arr[i][0]] + arr[i][1]);
        }
    }

    /*
    for(int i = 1; i <= n; i++){
        for(int w = 1; w <= k; w++)
            printf("%d ", v[i][w]);
        printf("\n");
    }
    */

    printf("%d", v[n][k]);
}