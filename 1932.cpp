#include <cstdio>
#include <algorithm>
using namespace std;

enum {MAX = 500};

int in[MAX + 1] = {0, };
int temp[MAX + 1] = {0, };
int stack[MAX + 1] = {0, };

void add(int level){
    for(int i = 0; i < level; i++){
        if(i == 0){
            temp[0] = stack[0] + in[0];
        }
        else{
            temp[i] = max(stack[i - 1], stack[i]) + in[i];
        }
    }
    for(int i = 0; i < level; i++)
        stack[i] = temp[i];

    /*
    printf("---stack---\n");
    for(int i = 0; i < level; i++)
        printf("%d ", stack[i]);
    printf("\n");
    */
}

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++)    
            scanf("%d", &in[j]);
        add(i + 1);
    }

    int maxResult = 0;
    for(int i = 0; i < n; i++){
        if(stack[i] > maxResult)
            maxResult = stack[i];
    }

    printf("%d", maxResult);
}