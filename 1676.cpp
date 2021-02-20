#include <cstdio>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    int count = 0;
    for(int i = 5; i <= n; i++){
        for(int div = 5; div <= i; div *= 5)
            if(i % div == 0)
                count++;
    }

    printf("%d", count);
}