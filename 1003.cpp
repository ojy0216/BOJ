#include <iostream>
using namespace std;

int mem[2];

void f(int n){
    while(n > 1){
        int tmp = mem[0] + mem[1];
        mem[0] = mem[1];
        mem[1] = tmp;
        n--;
    }
}

int main(){
    int t;
    scanf("%d", &t);

    for(int i = 0; i < t; i++){
        mem[0] = 0;
        mem[1] = 1;
        int n;
        scanf("%d", &n);
        if(n == 0)
            printf("1 0\n");
        else if(n == 1)
            printf("0 1\n");
        else{
            f(n);
            printf("%d %d\n", mem[0], mem[1]);
        }
    }
}