#include <cstdio>
using namespace std;

int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    int result = 1;
    for(int i = 0; i < k; i++)
        result *= (n - i);

    for(int i = k; i > 0; i--)
        result /= i;

    printf("%d", result);
}