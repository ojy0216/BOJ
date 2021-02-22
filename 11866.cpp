#include <cstdio>
#include <queue>
using namespace std;

int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    queue<int> q;
    for(int i = 1; i <= n; i++)
        q.emplace(i);

    printf("<");
    while(!q.empty()){
        for(int i = 0; i < k - 1; i++){
            int tmp = q.front();
            q.pop();
            q.emplace(tmp);
        }
        printf("%d", q.front());
        if(q.size() != 1)
            printf(", ");
        q.pop();
    }
    printf(">");
}