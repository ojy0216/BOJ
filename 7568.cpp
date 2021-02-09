#include <iostream>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    int **p = new int* [n];
    for(int i = 0; i < n; i++)
        p[i] = new int [2];

    int *r = new int [n];

    int x, y;
    for(int i = 0; i < n; i++)
        scanf("%d %d", &p[i][0], &p[i][1]);

    for(int i = 0; i < n; i++){
        int count = 1;
        for(int j = 0; j < n; j++){
            if(i != j){
                if(p[i][0] < p[j][0] && p[i][1] < p[j][1])
                    count++;
            }
        }
        r[i] = count;
    }

    for(int i = 0; i < n; i++)
        printf("%d ", r[i]);

    delete [] r;
    for(int i = 0; i < n; i++)
        delete [] p[i];
    delete [] p;
}