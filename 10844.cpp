#include <cstdio>
using namespace std;

int arr[10] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1};
int tmp[10] = {0, };

void f(){
    tmp[0] = arr[1];
    for(int i = 1; i <= 8; i++)
        tmp[i] = (arr[i - 1] + arr[i + 1]) % 1000000000;
    tmp[9] = arr[8];

    for(int i = 0; i < 10; i++)
        arr[i] = tmp[i];
}

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 1; i < n; i++)
        f();

    int sum = 0;
    for(int i = 0; i < 10; i++)
        sum = (sum + arr[i]) % 1000000000;

    printf("%d", sum);
}