#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    queue<int> q;
    for(int i = 0; i < n; i++){
        char op[6];
        scanf("%s", op);

        if(strcmp(op, "push") == 0){
            int tmp;
            scanf("%d", &tmp);
            q.push(tmp);
        }
        else if(strcmp(op, "pop") == 0){
            if(q.empty())
                printf("-1\n");
            else{
                printf("%d\n", q.front());
                q.pop(); 
            }
        }
        else if(strcmp(op, "size") == 0)
            printf("%d\n", q.size());
        else if(strcmp(op, "empty") == 0)
            printf("%d\n", q.empty());
        else if(strcmp(op, "front") == 0){
            if(q.empty())
                printf("-1\n");
            else
                printf("%d\n", q.front());
        }
        else{
            if(q.empty())
                printf("-1\n");
            else
                printf("%d\n", q.back());
        }
    }
}