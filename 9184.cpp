#include <iostream>
using namespace std;

int arr[21][21][21] = {0, };

int w(int a, int b, int c){
    if(a <= 0 || b <= 0 || c <= 0)
        return 1;
    else if(a > 20 || b > 20 || c > 20){
        if(arr[20][20][20] == 0)
            arr[20][20][20] = w(20, 20, 20);
        return arr[20][20][20];
    }
    else if(a < b && b < c){
        if(arr[a][b][c] == 0)
            arr[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a , b - 1, c);
        return arr[a][b][c];
    }
    else{
        if(arr[a][b][c] == 0)
            arr[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
        return arr[a][b][c];
    }
}

int main(){
    while(true){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if((a == -1) && (b == -1) && (c == -1))
            break;
        printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
    }
}