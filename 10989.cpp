#include <iostream>
#include <vector>
using namespace std;

enum {MAX_DATA = 10001};

int main(){
    int n;
    scanf("%d", &n);

    int arr[MAX_DATA] = {0, };

    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        arr[x]++;
    }

    for(int i = 0; i < MAX_DATA; i++){
        for(int j = 0; j < arr[i]; j++)
            printf("%d\n", i);
    }
}