#include <iostream>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 1; i < n; i++){
        int sum = i;
        int x = i;
        while(x > 0){
            sum += x % 10;
            x /= 10;
        }

        if(sum == n){
            printf("%d", i);
            return 0;
        }
    }
    printf("%d", 0);
}