#include <cstdio>
using namespace std;

enum {MAX = 101};

long long arr[MAX] = {0, 1, 1, 1, 2, 2, };

int main(){
    int t;
    scanf("%d", &t);

    for(int i = 6; i <= MAX - 1; i++)
        arr[i] = arr[i - 1] + arr[i - 5];

    for(int i = 0; i < t; i++){
        int n;
        scanf("%d", &n);
        printf("%lld\n", arr[n]);
    }
}