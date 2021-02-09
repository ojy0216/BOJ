#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX 1000000

int arr[MAX + 1] = {0, };

void f(int n){
    if(n <= 3)
        return;

    int x, y, z;
    bool div2 = false, div3 = false;
    if(n % 2 == 0){
        div2 = true;
        if(arr[n / 2] == 0)
            f(n / 2);
        x = arr[n / 2];
    }
    if(n % 3 == 0){
        div3 = true;
        if(arr[n / 3] == 0)
            f(n / 3);
        y = arr[n / 3];
    }
    if(arr[n - 1] == 0)
        f(n - 1);
    z = arr[n - 1];

    if(div2 && !div3)
        arr[n] = min(x, z) + 1;
    else if(!div2 && div3)
        arr[n] = min(y, z) + 1;
    else if(div2 && div3)
        arr[n] = min(x, min(y, z)) + 1;
    else
        arr[n] = z + 1;
}

int main(){
    int n;
    scanf("%d", &n);

    arr[1] = 0;
    arr[2] = 1;
    arr[3] = 1;

    f(n);

    printf("%d", arr[n]);
}