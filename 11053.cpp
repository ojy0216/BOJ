#include <cstdio>
using namespace std;

#define MAX 1000

int arr[MAX] = {0, };
int length[MAX] = {1, 0, };

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for(int i = 1; i < n; i++){
        int max = 0;
        for(int j = 0; j < i; j++){
            if(arr[j] < arr[i]){
                if(length[j] > max){
                    max = length[j];
                }
            }
        }
        if(max == 0)
            length[i] = 1;
        else
            length[i] = max + 1;
    }

    int max = 0;
    for(int i = 0; i < n; i++){
        if(length[i] > max)
            max = length[i];
    }
    
    printf("%d", max);
}